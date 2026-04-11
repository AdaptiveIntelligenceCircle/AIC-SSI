#pragma once 
#include <iostream>
using namespace std; 

#include <optional>
#include <memory> 
#include <unordered_set>

namespace aic :: ssi :: storage
{
    class StorageProvider; 
}

namespace aic :: ssi :: vc 
{
    class RevocationRegistry 
    {
        public: 
        explicit RevocationRegistry(shared_ptr<aic :: ssi :: storage::StorageProvider> storage);
        bool revoke(const string &credentialId, const string &reason); 
        bool isRevoked(const string &credentialId); 

        bool load(); 
        bool save(); 

        private: 
        shared_ptr<aic :: ssi :: storage :: StorageProvider> m_storage; 
        unordered_set<string> m_revoked; 

        string m_storageKey = "vc/revocation_registry.json"; 

        optional<string> readRaw(); 
    }; 
} // namespace aic :: ssi :: vc 