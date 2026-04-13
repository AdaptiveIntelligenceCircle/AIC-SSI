#pragma once 
#include <string> 

#include <optional>
#include <nlohmann/json.hpp>

using namespace std; 

namespace aic :: ssi :: wallet 
{
    struct WalletProfile 
    {
        string walletId; 
        string ownerDID; 

        string created; 
        string updated; 

        string kdfAlgorithm; 
        string encryptionAlgorithm; 

        int kdfIterations = 200000;
        string salt; 

        nlohmann :: json metadata; 

        nlohmann:: json toJson() const; 
        static optional<WalletProfile> fromJson(const nlohmann:: json &j); 

        bool isValidBasic() const; 
    }; 
}