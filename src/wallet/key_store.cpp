#include "key_store.h"

namespace aic :: ssi :: wallet 
{
    KeyStore :: KeyStore(
        shared_ptr<aic::ssi::storage::StorageProvider> storage,
        shared_ptr<aic::ssi::crypto::CryptoProvider> crypto
    )
    {
        m_storage = move(storage);
        m_crypto = move(crypto); 
    }

    string KeyStore :: keyPath(const string &keyId) const 
    {
        return "wallet/keystore/" + keyId + ".json"; 
    }

    bool KeyStore :: putPrivateKey(const string &keyId, 
    const string &privateKeyRaw, 
    const string &masterKey)
    {
        if (!m_storage or !m_crypto) return false; 
        
        if (keyId.empty() or privateKeyRaw.empty() or masterKey.empty())
        return false;

        // Crypto Provider should encrypt using masterKey.. 
        //auto encOpt = m_crypto -> encrypt(masterKey, privateKeyRaw); 
        // if (!encOpt.has_value()) return false; 

        nlohmann :: json j;
        j["keyId"] = keyId; 
        j["encryptedPrivateKey"]; 

    }

    optional<string> KeyStore:: getPrivateKey(const string &keyId, const string &masterKey)
    {
        if (!m_storage or !m_crypto) return nullopt; 
        if (keyId.empty() or masterKey.empty()) return nullopt; 

        string raw; 
        if (!m_storage) return nullopt; 

        try 
        {
            auto j = nlohmann :: json :: parse(raw); 
            if (j.contains("encryptedPrivateKey") or !j[""])
            return nullopt; 

            auto enc = j["encryptedPrivateKey"].get<string>(); 
        } catch (...)
        {
            return nullopt; 
        }
    }

    bool KeyStore :: putPublicKey(const string &keyId, 
    const string &publicKeyRaw)
    {
        if (!m_storage) return false; 
        if (keyId.empty() or publicKeyRaw.empty()) return false; 

        nlohmann :: json j; 
        j["keyId"] = keyId; 
        j["publicKey"] = publicKeyRaw; 
    }

    optional<string> KeyStore :: getPublicKey(const string &keyId)
    {
        if (!m_storage) return nullopt; 
        if (keyId.empty()) return nullopt; 

        string raw; 

        try 
        {
            auto j = nlohmann :: json :: parse(raw); 
            if (!j.contains("publickey") or !j["publickey"].is_string())
            return nullopt; 
            return j["publicKey"].get<string>();
        }
        catch (...)
        {
            return nullopt; 
        }
    }

    bool KeyStore :: removeKey(const string &keyId)
    {
        if (!m_storage) return false; 
        //return m_storage -> remove(keyPath(keyId)); 
    }
}