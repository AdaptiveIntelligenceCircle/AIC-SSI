#pragma once 
#include <string>

#include "../keypair.h"
#include <optional>

namespace aic :: ssi :: crypto :: pqc 
{
    // PQC provider abstraction.. 
    // Later integrate OpenQuantumSafe (liboqs)...
    class PQCProvider 
    {
        public: 
        virtual ~PQCProvider() = default; 

        virtual KeyPair generateKeyPair(const string &algorithm) = 0; 
        virtual optional<string> sign(const string &privateKey, const string &message) = 0;

        virtual bool verify(const string &publicKey, const string &message, const string &signature)  = 0; 

        virtual optional<string> encapsulate(const string &publicKey) = 0; 
        virtual optional<string> decapsulate(const string &privateKey, const string &ciphertext) = 0 ;
    }; 
} // namespace aic :: ssi :: crypto :: pqc