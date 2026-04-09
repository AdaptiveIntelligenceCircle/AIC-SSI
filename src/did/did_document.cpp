#include "did_document.h"
using namespace std; 

namespace aic :: ssi :: did 
{
    nlohmann:: json VerificationMethod :: toJson() const 
    {
        return 
        {
            {"id", id}, 
            {"type", type}, 
            {"controller", controller}, 
            {"publickey", publickey}
        };
    }

    optional<VerificationMethod> VerificationMethod :: fromJson(const nlohmann :: json &j)
    {
        if (!j.object()) return nullopt; 

        VerificationMethod vm; 

        if (!j.contains("id") or !j["id"].is_string())
        return nullopt; 
        if (!j.contains("type") or !j["type"].is_string())
        return nullopt; 
        if (!j.contains("controller") or !j["controller"].is_string())
        return nullopt; 
        if (!j.contains("publickey") or !j["publickey"].is_string())
        return nullopt; 

        vm.id = j["id"].get<string>(); 
        vm.type = j["type"].get<string>(); 
        vm.controller = j["controller"].get<string>(); 
        vm.publickey = j["publickey"].get<string>(); 

        return vm; 
    }

    nlohmann :: json DIDDocument :: toJson() const 
    {
        nlohmann :: json j;
        j["id"] = id; 
        j["created"] = created;
        j["updated"] = updated;

        j["verificationMethods"] = nlohmann :: json ::array(); 
        for (const auto &vm: verificationMethods)
        {
            j["verificationMethods"].push_back(vm.toJson()); 
        }

        j["services"]  = nlohmann:: json::array(); 
        for (const auto &s : services)
        {
            j["services"].push_back(s.toJson()); 
        }
        return j; 
    }

    optional<DIDDocument> DIDDocument::fromJson(const nlohmann::json& j) {
    if (!j.is_object()) return std::nullopt;

    DIDDocument doc;

    if (!j.contains("id") || !j["id"].is_string()) return std::nullopt;
    doc.id = j["id"].get<std::string>();

    if (j.contains("created") && j["created"].is_string())
        doc.created = j["created"].get<std::string>();

    if (j.contains("updated") && j["updated"].is_string())
        doc.updated = j["updated"].get<std::string>();

    if (j.contains("verificationMethods") && j["verificationMethods"].is_array()) {
        for (const auto& item : j["verificationMethods"]) {
            auto vm = VerificationMethod::fromJson(item);
            if (vm) doc.verificationMethods.push_back(*vm);
        }
    }

    if (j.contains("services") && j["services"].is_array()) {
        for (const auto& item : j["services"]) {
            auto se = ServiceEndpoint::fromJson(item);
            if (se) doc.services.push_back(*se);
        }
    }

    if (!doc.isValidBasic()) return std::nullopt;
    return doc;
    }

bool DIDDocument::isValidBasic() const 
{
    if (id.empty()) return false;
    if (verificationMethods.empty()) return false;

    // At least one key should be controlled by the DID itself
    bool hasControllerKey = false;
    for (const auto& vm : verificationMethods) {
        if (vm.controller == id) {
            hasControllerKey = true;
            break;
        }
    }
    return hasControllerKey;
}

}