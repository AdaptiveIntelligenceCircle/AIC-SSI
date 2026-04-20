#pragma once 
#include "storage_provider.h"

#include <unordered_map>
using namespace std; 

#include <mutex>

namespace aic :: ssi :: storage 
{
    // In Memory storage backend for tests/simulation.. 
    class MemoryStorage : public StorageProvider
    {
        public:
        MemoryStorage() = default; 
        bool put(const string &key, const string &value) override;
        bool get(const string &key, string &out) override; 
        bool remove(const string &key) const; 

        bool exists(const string &key) override; 
        vector<string> listKeys(const string &prefix) override; 

        private: 
        unordered_map<string, string> m_data; 
        mutex m_mutex; 
    }; 
} // namespace aic :: ssi :: storage..