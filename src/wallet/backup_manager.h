#pragma once 
#include <string> 

#include <optional> 
#include <memory> 

#include <iostream>
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
    // Backup Manager exports wallet data into encrypted 
    class BackupManager 
    {
        public:
        BackupManager(shared_ptr<aic::ssi::storage::StorageProvider> storage, 
        shared_ptr<aic::ssi::crypto::CryptoProvider> crypto);
        
        optional<string> exportEncrypted(const string &masterKey);
        bool importEncryptBackup(const string &blob, const string &masterKey);
        
        private: 
        shared_ptr<aic::ssi::storage::StorageProvider> m_storage;
        shared_ptr<aic::ssi::crypto::CryptoProvider> m_crypto;
        
    }; 
}