#pragma once 
#include <string> 

#include <vector> 
#include <optional> 

#include <iostream>
#include <nlohmann/json.hpp>
using namespace std; 

namespace aic :: ssi :: vc
{
    struct VerifiableCredential
    {
        string id; 
        string issuer; 
        string subject;

        string issuranceDate; 
        string expirationDate; 

        vector<string> types; 
        vector<string> contexts;

        nlohmann :: json claims;

        // proof object stored as json for extensibility.. 
        nlohmann:: json proof; 

        bool isExpired(const string &nowISO8601) const; 
        nlohmann :: json toJson() const; 

        static optional<VerifiableCredential> fromJson(const nlohmann :: json &j); 
        bool isValidBasic() const; 
    }; 
} // namespace aic :: ssi :: vc 