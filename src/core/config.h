#pragma once 
#include <iostream>

#include "status.h"
#include <cstddef>
#include <string> 

using namespace std; 

namespace aic :: ssi :: core  
{
    struct EngineConfig final 
    {
        string instance_name = "aic-ssi"; 
        string version = "1.0"; 
        size_t max_modules = 32; 

        // Validate configurations before any module is initialized..// 
        [[nodiscard]] Status validate() const; 
    }; 
}   