#pragma once 

#include <string> 
#include <optional>

#include "keypair.h"
using namespace std; 

namespace aic :: ssi :: crypto 
{
    // CryptoProvider is the single integration surface used by DID/VC/wallet.. 

    class CryptoProvider
    {
        public: 
        virtual ~CryptoProvider() = default; 

        virtual string hashHex(const string &data) = 0; 

        virtual optional<string> encrypt(const string &key, const string &plaintext) = 0; 

        virtual optional<string> decrypt(const string &key, const string &ciphertext) = 0; 

        virtual optional<string> signRaw(const string &privateKeyRaw, const string &message) =0; 

        virtual bool verifyRaw(const string &publicKeyRaw, const string &message, const string &signature) = 0;

        // Sign using a key reference (DID or KeyID).. 
        // wallet can map key Ref -> privateKeyRaw.. 

        virtual optional<string> sign(const string &keyRef, const string &message) = 0; 

        virtual KeyPair generateKeyPair(const string &algorithm) = 0; 
    }; 
} // namespace aic :: ssi :: crypto