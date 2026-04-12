#pragma once 
#include <string> 
#include <vector>
#include "vc.h"
#include <optional>
#include <nlohmann/json.hpp>
using namespace std; 

namespace aic :: ssi :: vc 
{
    struct VerifiablePresentation 
    {
        string id; 
        string holder; 

        vector<string> types;
        vector<string> contexts; 

        vector<VerifiableCredential> credentials; 

        nlohmann :: json proof; 
        nlohmann :: json toJson() const; 

        bool isValidBasic() const; 
        static optional<VerifiablePresentation> fromJson(const nlohmann :: json &j);

    }; // namespace aic :: ssi :: vc 
}