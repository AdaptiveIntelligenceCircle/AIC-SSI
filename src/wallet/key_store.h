#pragma once 
#include <string>

#include <unordered_map>
#include <optional> 

#include <memory> 
#include <nlohmann/json.hpp>
using namespace std; 

namespace aic :: ssi :: storage 
{
    class StorageProvider; 
}

namespace aic :: ssi :: crypto 
{
    class CryptoProvider; 
}

namespace aic :: ssi :: wallet 
{
    // Key Store stores encrypted key material.. 
    // It does not decide access. It only stores..

    class KeyStore 
    {
        public: 
        KeyStore(shared_ptr<aic::ssi::storage::StorageProvider> storage,
        shared_ptr<aic::ssi::crypto::CryptoProvider> crypto);
        
        bool putPrivateKey(const string &keyId, const string &privateKeyRaw, const string &masterKey); 

        optional<string> getPrivateKey(const string &keyId, const string &masterKey); 

        bool putPublicKey(const string &keyId, const string &publicKeyRaw); 

        optional<string> getPublicKey(const string &keyId);
        bool removeKey(const string &keyId); 

        private: 
        shared_ptr<aic::ssi::storage::StorageProvider> m_storage; 
        shared_ptr<aic::ssi::crypto::CryptoProvider> m_crypto; 

        string keyPath(const string &keyId) const; 
    }; 

}