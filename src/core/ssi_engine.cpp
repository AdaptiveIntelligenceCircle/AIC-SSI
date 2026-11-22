#include "ssi_engine.h"
#include <stdexcept> 

#include <utility> 
using namespace std; 

namespace aic :: ssi :: core 
{
    SSIEngine :: SSIEngine (EngineConfig config)
    : config_(move(config)), context_(config_), 
    modules_(config_.max_modules)
    {
        const auto valid = config_.validate(); 
        if (!valid) 
        {
            state_ = LifecycleState :: Failed; 
            throw invalid_argument(valid.message()) ; 
        }
        (void) transition(LifecycleState :: Configured); 
    }

    SSIEngine :: ~SSIEngine()
    {
        try {
            (void) stop() ; 
        }

        catch(...)
        {

        }
    }

    Status SSIEngine :: transition(LifecycleState next)
    {
        auto valid = validate_transition(state_, next); 
        if (!valid) return valid; 
        state_ = next; 
        return Status :: success(); 
    }

    Status SSIEngine :: register_module(unique_ptr<IModule> module)
    {
        if (state_ != LifecycleState :: Configured)
        {
            return Status :: failure("modulers can only be registered while the engine is configured"); 
        }
        return modules_.add(move(module)); 
    }

    Status SSIEngine :: initialize()
    {
        if (state_ != LifecycleState :: Configured)
        {
            return Status :: failure("Engine must be configured before initialization"); 
        }

        (void) transition(LifecycleState :: Initializing); 
        auto status = modules_.initialize_all(context_); 
        if (!status) {
            (void) transition(LifecycleState :: Failed); 
            return status ;
        }
        return transition(LifecycleState :: Ready); 
    }

    Status SSIEngine :: start()
    {
        if (state_ != LifecycleState :: Ready)
        {
            return Status :: failure("engine must be ready before it can start"); 
        }
        return transition(LifecycleState ::Running); 
    }

    Status SSIEngine :: stop()
    {
        if (state_ == LifecycleState :: Stopped) return Status :: success(); 
        if (state_ == LifecycleState :: Failed)
        {
            (void) modules_.shutdown_all(context_) ; 
            return Status :: failure("engine is in failed state ; recovery is not implemented"); 
        }

        if (state_ != LifecycleState :: Ready and state_!= LifecycleState :: Running)
        {
            return Status :: failure("engine cannot be stopped from its current state"); 
        }

        (void) transition(LifecycleState :: Stopping); 
        auto status = modules_.shutdown_all(context_);
        if (!status)  
        {
            (void)transition(LifecycleState :: Failed); 
            return status; 
        }
        return transition(LifecycleState :: Stopped); 
    }

    LifecycleState SSIEngine :: state() const noexcept 
    {
        return state_; 
    }

    LifecycleState SSIEngine :: context() noexcept 
    {
        return context_;
    }

    const EngineConfig &SSIEngine :: config() const noexcept 
    {
        return config_; 
    }
}