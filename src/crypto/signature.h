#pragma once 
#include <iostream>

#include <string> 
#include <optional>

using namespace std; 

namespace aic :: ssi :: crypto 
{
    class Signature 
    {
        public: 
        static optional<string> sign(const string &privateKeyRaw, const string &message); 

        static bool verify(const string &publicKeyRaw, 
        const string &message, const string &signature); 
    }; 
} // namespace aic :: ssi :: crypto..