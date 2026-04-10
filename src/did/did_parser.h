#pragma once 
#include <string>

#include <optional> 
#include "did.h"
namespace aic :: ssi :: did 
{
    class DIDParser 
    {
        public: 
        static optional<DID> parse(const string&did); 
        static bool isValid(const string &did); 
    }; 
}