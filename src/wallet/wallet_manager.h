#pragma once 
#include <memory> 

#include <optional> 
#include <string> 

#include "wallet.h"
#include "backup_manager.h"

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
    // Wallet Manager is orchestration layer for wallet lifecycle.. 
    // IT is "core - friendly" and can integrate.. 

    class WalletManager 
    {
        public: 
        WalletManager(shared_ptr<aic::ssi::storage::StorageProvider> storage
        , shared_ptr<aic::ssi::crypto::CryptoProvider> crypto);
        
        shared_ptr<Wallet> wallet(); 

        bool createWallet(const string &ownerDID, const string &password); 
        bool createWallet(const string &password); 

        void lockWallet(); 

        optional<string>backup(const string &password); 
        bool restore(const string &backupBlob, const string &password); 

        private: 
        shared_ptr<aic::ssi::storage::StorageProvider> m_storage; 
        shared_ptr<aic::ssi::crypto::CryptoProvider> m_crypto; 

        shared_ptr<AccessControl> m_access;
        shared_ptr<Wallet> m_wallet; 
        shared_ptr<BackupManager> m_backup; 

    }; 
}