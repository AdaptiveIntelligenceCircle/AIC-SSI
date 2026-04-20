#pragma once 
#include <string>

#include <optional>
#include <vector> 

using namespace std;

namespace aic :: ssi :: storage 
{
    // Storage Provider is abstract KV/object backend.. 
    // AIC principle : core logic never depends on file/sqlite/ipfs directly.. 

    class StorageProvider
    {
        public: 
        virtual ~StorageProvider() = default; 
        virtual bool put(const string &key, const string &value) = 0; 
        virtual bool get(const string &key, string &out) = 0; 
        virtual bool remove(const string &key) = 0; 

        virtual bool exists(const string &key) = 0; 
        virtual vector<string> listKeys(const string &prefix); 
    }; 
} // namespace aic :: ssi :: storage.. 