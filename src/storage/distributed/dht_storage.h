#pragma once
#include "../storage_provider.h"

#include <string>

namespace aic :: ssi :: storage :: distributed 
{
    // DHT Storage placeholder..
    // Later integrate Kademlia or libp2p DHT..

    class DHTStorage : public StorageProvider 
    {
        public: 
        explicit DHTStorage(const string &nodeId); 

        bool put(const string &key, const string &value) override; 
        bool get(const string &key, string &out) override; 
        bool remove(const string &key) override ; 

        bool exists(const string &key) override; 
        vector<string> listKeys(const string &prefix) override; 

        private: 
        string m_nodeId; 
    }; 
} // namespace aic :: ssi :: storage :: distributed..