#pragma once 

#include "config.h"
#include <mutex> 

#include <optional> 
#include <string> 

#include <unordered_map>
using namespace std; 

namespace aic :: ssi :: core 
{
    // Runtime scoped, process-level key/value context.. Not a credential store..// 
    class EngineContext final 
    {
        public: 
        explicit EngineContext (EngineConfig config); 

        [[nodiscard]] const EngineConfig &config() const; 
        void set(string key, stting value); 
        [[nodiscard]] optional<string>get(const string &key) const; 
        [[nodiscard]] bool erase(const string &key); 
        void clear(); 

        private: 
        EngineConfig config_; 
        mutable mutex mutex_; 
        unordered_map<string, string> values_; 
    }; 
}