#pragma once 

#include "context.h"
#include "status.h"

#include <string> 
#include <string_view> 

using namespace std; 

namespace aic :: ssi :: core 
{
    // Extension point for SSI Ecosystem 
    class IModule
    {
        public: 
        virtual ~IModule() = default; 
        [[nodiscard]] virtual string_view id() const noexcept = 0; 
        [[nodiscard]] virtual string_view version() const noexcept  = 0; 
        virtual Status initialize(EngineContext &context) = 0;
        virtual Status shutdown(EngineContext &context) = 0; 
    }; 
}