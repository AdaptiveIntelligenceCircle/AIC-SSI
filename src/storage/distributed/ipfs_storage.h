#pragma once 
#include "../storage_provider.h"

#include <string>
using namespace std; 

namespace aic :: ssi :: storage :: distributed 
{
    // IPFS Storage placeholder.. 
    // Later integrate ipfs - http - client or libipfs.. 

    class IPFSStorage : public StorageProvider 
    {
        public: 
        explicit IPFSStorage (const string &gatewayUrl); 

        bool put(const string &key, const string &value) override; 
        bool get(const string &key, string &out) override; 
        bool remove(const string &key) override; 

        bool exists(const string &key) override; 
        vector<string> listKeys(const string &prefix) override; 

        private: 
        string m_gateway; 
    }; 
}