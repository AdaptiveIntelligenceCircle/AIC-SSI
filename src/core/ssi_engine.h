#pragma once 

#include "lifecycle.h"
#include "module_registry.h"

using namespace std; 

namespace aic :: ssi :: core 
{
    // Coordinates module lifecycle, it does not issue or verify credentials itself...// 
    class SSIEngine final 
    {
        public: 
        explicit SSIEngine (EngineConfig config = {}); 
        SSIEngine(const SSIEngine &)= delete; 
        SSIEngine &operator=(const SSIEngine &) = delete; 
        ~SSIEngine(); 

        Status register_module(unique_ptr<IModule> module); 
        Status initialize(); 
        Status stop(); 
        Status start(); 

        [[nodiscard]] LifecycleState state() const noexcept; 
        [[nodiscard]] EngineContext &context() noexcept; 
        [[nodiscard]] const EngineConfig &config() const noexcept; 

        private:
        Status transition(LifecycleState next); 

        EngineConfig config_; 
        EngineContext context_; 
        ModuleRegistry modules_; 
        LifecycleState state_ {
            LifecycleState :: Created
        }; 
    }; 
}