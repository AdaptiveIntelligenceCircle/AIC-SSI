#pragma once 
#include "storage_provider.h"

#include <string>
#include <mutex>

#include <iostream>
using namespace std;

namespace aic :: ssi :: storage 
{
    // SQL Lite backend placeholder.. 
    // Real Implementation requires sqlite 3 dependency.. 

    class SQLiteStorage : public StorageProvider
    {
        public: 
        explicit SQLiteStorage(const string &dbPath); 

        bool put(const string &key, const string &value) override; 
        bool get(const string &key, string &out) override; 
        bool remove(const string &key) override; 

        bool exists(const string &key) override; 
        vector<string> listKeys(const string &prefix) override; 

        private:
        string m_dbPath; 
        mutex m_mutex; 
    }; 
}