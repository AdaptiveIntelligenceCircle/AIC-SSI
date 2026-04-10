#pragma once 
#include <string>
#include <unordered_map>
#include <memory> 

#include <optional>
#include "did_method.h"
#include "did_parser.h"
using namespace std; 

namespace aic :: ssi :: did 
{
    class DIDResolver
    {
        public: 
        DIDResolver() = default; 

        void registerMethod(shared_ptr<DIDMethod> method); 

        optional<DIDDocument> resolve(const string &did); 

        private: 
        unordered_map<string, shared_ptr<DIDMethod>> m_methods;
    }; 
}