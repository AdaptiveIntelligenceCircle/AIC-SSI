#pragma once 
#include <string> 
#include <optional>

#include "../keypair.h"
using namespace std; 

namespace aic :: ssi :: crypto :: pqc 
{
    // Placeholder kyber KEM.. 
    // Real Kyber must use liboqs or pqclean.. 

    class Kyber 
    {
        public: 
        static KeyPair generate(); 
        
        static optional<string> encapsulate(const string &publicKey); 
        static optional<string> decapsulate(const string &privateKey, const string &ciphertext); 
    }; 
} // namespace aic :: ssi :: crypto :: pqc.. 