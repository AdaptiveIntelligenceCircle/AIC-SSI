#pragma once 
#include <iostream>

#include <nlohmann/json.hpp>

#include <vector>
using namespace std;

namespace aic :: ssi :: did
{
    struct VerificationMethod 
    {
        string id; 
        string type; 
        string controller; 
        string publickey; 

        nlohmann :: json toJson() const; 
        static optional<VerificationMethod> fromJson(const nlohmann :: json &j);
    };  

    struct ServiceEndpoint
    {
        string id; 
        string type; 
        string endpoint;

        nlohmann :: json toJson() const; 
        static optional<ServiceEndpoint> fromJson(const nlohmann :: json &j); 
    }; 

    struct DIDDocument 
    {
        string id; 
        string created;
        string updated; 

        vector<VerificationMethod> verificationMethods; 
        vector<ServiceEndpoint> services; 

        nlohmann::json toJson() const; 
        static optional<DIDDocument> fromJson(const nlohmann::json &j); 

        bool isValidBasic() const; 
    }; 
} // namespace aic :: ssi :: did