#pragma once 
#include <string> 

#include <optional>
#include "../keypair.h"

using namespace std; 

namespace aic :: ssi :: crypto :: pqc 
{
    // Placeholder Dilithium signature scheme..
    class Dilithium 
    {
        public:
        static KeyPair generate();

        static optional<string> sign(const string &privateKey, const string &message); 

        static bool verify(const string &publicKey, 
        const string &message, const string &signature); 
    }; 
} // namespace aic :: ssi :: crypto :: pqc