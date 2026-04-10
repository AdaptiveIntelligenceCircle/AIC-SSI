#pragma once 
#include <string>

#include <optional> 
#include "did_document.h"

using namespace std; 

namespace aic :: ssi :: did
{
    struct DIDCreateRequest
    {
        string type;
        string publicKey; 
        string keyType;
        string hint; 
    }; 

    class DIDMethod 
    {
        public: 
        virtual ~DIDMethod() = default;

        virtual string methodName() const = 0;

        virtual optional<DIDDocument>
        create(const DIDCreateRequest &req) = 0; 

        virtual optional<DIDDocument>
        resolve(const string &did) = 0;
    }; 
}