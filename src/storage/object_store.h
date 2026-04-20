#pragma once 
#include <string> 

#include <optional>
#include <memory>

#include <nlohmann/json.hpp>
using namespace std; 

namespace aic :: ssi :: storage 
{
    class StorageProvider; 

    // ObjectStore provides Json object storage wrapper.. 

    class ObjectStore 
    {
        public:
        explicit ObjectStore(shared_ptr<StorageProvider>provider);

        bool putJson(const string &key, const nlohmann :: json&obj); 
        optional<nlohmann :: json> getJson(const string &key); 

        bool putText(const string &key, const string &text); 
        optional<string> getText(const string &key); 

        bool remove(const string &key); 

        private: 
        shared_ptr<StorageProvider> m_provider; 
    }; 
}