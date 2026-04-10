#pragma once 
#include <string>
#include <optional>

#include <memory> 
#include "did_document.h"
using namespace std; 

namespace aic :: ssi :: storage 
{
    class StorageProvider; 
}

namespace aic :: ssi :: did 
{
    class DIDRegistry 
    {
        public:
        explicit DIDRegistry(shared_ptr<aic::ssi::storage::StorageProvider> storage); 

        bool store(const DIDDocument &doc); 
        optional<DIDDocument> load(const string &did); 
        bool exists(const string &did); 
        bool remove(const string &did); 

        private:
        shared_ptr<aic::ssi::storage::StorageProvider> m_storage ;
        string makeKey(const string &did) const; 
    };
}