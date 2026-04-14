#pragma once 
#include <string> 

#include <vector> 
#include <optional> 

#include <memory> 
#include <nlohmann/json.hpp>

#include "wallet_profile.h"
#include "access_control.h"

namespace aic :: ssi:: crypto 
{
    class CryptoProvider;
}

namespace aic :: ssi :: storage
{
    class StorageProvider; 
}

namespace aic :: ssi :: wallet 
{
    class KeyStore; 

    class Wallet 
    {
        public: 
        Wallet(shared_ptr<aic::ssi::storage::StorageProvider> provider, 
        shared_ptr<aic::ssi::crypto::CryptoProvider>crypto, 
        shared_ptr<AccessControl> AccessControl);
        
        bool createNew(const string &ownerDID, const string &password);
        bool unlock(const string &password);
        void lock();

        optional<WalletProfile> getProfile() const; 

        // Key Operations.. 
        bool storePrivateKey(const string &keyId, const string &password); 
        optional<string> loadPrivateKey(const string &keyId);
        
        bool storePublicKey(const string &keyId, const string &publicKeyRaw); 
        optional<string> loadPublickey(const string &publicKeyRaw);
        
        // credential store (MVP as Json list).. 
        bool storeCredential(const nlohmann :: json &vcJson); 
        vector<nlohmann:: json> listCredentials(); 

        // Signing.. 
        optional<string>sign(const string &keyId, const string &password );

        private: 
        shared_ptr<aic::ssi::storage::StorageProvider> m_storage; 
        shared_ptr<aic::ssi::crypto::CryptoProvider> m_crypto; 

        shared_ptr<AccessControl> m_access; 
        shared_ptr<KeyStore> m_keystore;

    }; 
}