#pragma once 
#include <string>
#include <optional>

#include <nlohmann/json.hpp>
using namespace std; 

namespace aic :: ssi :: utils 
{
    // Thin wrapper around nlohmann/json..
    // AIC principle : parsing must be safe and predictable.. 

    class Json 
    {
        public: 
        static optional<nlohmann :: json> parse(const string &raw);
        
        static string stringify(const nlohmann :: json &j, int indent = 4); 
        static bool isObject(const nlohmann :: json &j); 
        static bool isArray(const nlohmann :: json &j); 

    }; 
} 