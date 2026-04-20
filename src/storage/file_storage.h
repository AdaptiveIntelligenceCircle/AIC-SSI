#pragma once 
#include "storage_provider.h"

using namespace std; 

#include <filesystem> 
#include <mutex>

namespace aic :: ssi :: storage 
{
    // FileStorage stores each key as a file under root directory.. 
    // It is simple, portable, and audit friendly..

    class FileStorage : public StorageProvider 
    {
        public: 
        explicit FileStorage(const string &rootDir); 

        bool put(const string &key, const string &value) override; 
        bool get(const string &key, string &out) override; 
        bool remove(const string &key) override; 

        bool exists(const string &key) override; 
        vector<string> listKeys(const string &prefix) override; 

        private:
        filesystem:: path m_root;
        mutex m_mutex; 

        filesystem :: path keyToPath(const string &key) const; 
        bool ensureParentDir(const filesystem :: path &p); 
    };
} // namespace aic :: ssi :: storage.. 