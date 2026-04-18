#pragma once 
#include <string> 

#include <optional>
using namespace std; 

#include "../keypair.h"

namespace aic :: ssi :: crypto :: classic 
{
    // placholer ECDSA wrapper.. 
    // Real ECDSA must use OpenSSL... 

    class ECDSA 
    {
        public: 
        static KeyPair generate(); 

        static optional<string> sign(const string &privateKey, const string &message); 

        static bool verify(const string &publicKey, const string &message, const string &signature); 
    }; 
} // namespace aic :: ssi :: crypto :: classic 