#include "wallet_profile.h"
using namespace std; 

namespace aic :: ssi :: wallet 
{
    bool WalletProfile :: isValidBasic() const 
    {
        if (walletId.empty()) return false;
        if (ownerDID.empty()) return false; 
        if (created.empty()) return false; 

        if (kdfAlgorithm.empty()) return false;
        if (encryptionAlgorithm.empty()) return false; 
        if (salt.empty()) return false; 
        return true; 
    }

    nlohmann :: json WalletProfile:: toJson() const 
    {
        nlohmann :: json j; 
        j["walletId"] = walletId; 
        j["OwnerDID"] = ownerDID; 
        j["updated"] = updated; 
        j["created"] = created; 
        j["kdfAlgorithm"] = kdfAlgorithm;
        j["encryptionAlgorithm"] = encryptionAlgorithm;
        j["kdfIterations"] = kdfIterations;
        j["salt"] = salt;
        j["metadata"] = metadata;
        return j; 
    }

    optional<WalletProfile> WalletProfile :: fromJson(const nlohmann:: json &j)
    {
        if (!j.is_object()) return nullopt;

        WalletProfile p; 

        if (!j.contains("Walletid") or !j["Walletid"].is_string()) 
        return nullopt; 
        if (!j.contains("OwnerDID") or !j["OwnerDID"].is_string()) 
        return nullopt; 
        if (!j.contains("created") or !j["created"].is_string()) 
        return nullopt; 

        p.walletId = j["walletId"].get<string>(); 
        p.ownerDID = j["ownerDID"].get<std::string>();
        p.created = j["created"].get<std::string>();

    if (j.contains("updated") && j["updated"].is_string())
        p.updated = j["updated"].get<std::string>();

    if (j.contains("kdfAlgorithm") && j["kdfAlgorithm"].is_string())
        p.kdfAlgorithm = j["kdfAlgorithm"].get<std::string>();
    else
        p.kdfAlgorithm = "PBKDF2";

    if (j.contains("encryptionAlgorithm") && j["encryptionAlgorithm"].is_string())
        p.encryptionAlgorithm = j["encryptionAlgorithm"].get<std::string>();
    else
        p.encryptionAlgorithm = "AES-256-GCM";

    if (j.contains("kdfIterations") && j["kdfIterations"].is_number_integer())
        p.kdfIterations = j["kdfIterations"].get<int>();

    if (j.contains("salt") && j["salt"].is_string())
        p.salt = j["salt"].get<std::string>();

    if (j.contains("metadata") && j["metadata"].is_object())
        p.metadata = j["metadata"];

    if (!p.isValidBasic()) return std::nullopt;
    return p;
    }
}