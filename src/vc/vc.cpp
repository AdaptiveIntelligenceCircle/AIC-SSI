#include "vc.h"
using namespace std; 

namespace aic :: ssi :: vc 
{
    bool VerifiableCredential :: isValidBasic() const 
    {
        if (id.empty()) return false;
        if (issuer.empty()) return false; 

        if (subject.empty()) return false; 
        if (issuranceDate.empty()) return false;
        if (types.empty()) return false;
        if(contexts.empty()) return false;
        if(!claims.is_object()) return false;
        return true; 
    }

    bool VerifiableCredential :: isExpired(const string &nowISO8601) const 
    {
        if (expirationDate.empty()) return false;
        // MVP compare lexicographically because ISO 8601 sorts..
        return nowISO8601 >= expirationDate;
    }

    nlohmann :: json VerifiableCredential :: toJson() const 
    {
        nlohmann :: json j; 
        j["id"] = id; 
        j["issue"] = issuer; 
        j["subject"] = subject;
        j["issuanceDate"] = issuranceDate; 

        if (!expirationDate.empty())
        {
            j["expirationDate"] = expirationDate; 
        }

        j["contexts"] = contexts; 
        j["types"] = types; 
        j["claims"] = claims;

        if (!proof.is_null() and !proof.empty())
        j["proof"] = proof; 
        
        return j; 
    }

    optional<VerifiableCredential> VerifiableCredential::fromJson(const nlohmann::json& j) 
    {
    if (!j.is_object()) return nullopt;

    VerifiableCredential vc;

    if (!j.contains("id") || !j["id"].is_string()) return nullopt;
    if (!j.contains("issuer") || !j["issuer"].is_string()) return nullopt;
    if (!j.contains("subject") || !j["subject"].is_string()) return nullopt;
    if (!j.contains("issuanceDate") || !j["issuanceDate"].is_string()) return nullopt;

    vc.id = j["id"].get<string>();
    vc.issuer = j["issuer"].get<string>();
    vc.subject = j["subject"].get<string>();
    vc.issuranceDate = j["issuanceDate"].get<string>();

    if (j.contains("expirationDate") && j["expirationDate"].is_string())
        vc.expirationDate = j["expirationDate"].get<string>();

    if (!j.contains("@context") || !j["@context"].is_array()) return nullopt;
    for (const auto& c : j["@context"]) {
        if (c.is_string()) vc.contexts.push_back(c.get<string>());
    }

    if (!j.contains("type") || !j["type"].is_array()) return std::nullopt;
    for (const auto& t : j["type"]) {
        if (t.is_string()) vc.types.push_back(t.get<string>());
    }

    if (!j.contains("claims") || !j["claims"].is_object()) return nullopt;
    vc.claims = j["claims"];

    if (j.contains("proof") && j["proof"].is_object())
        vc.proof = j["proof"];

    if (!vc.isValidBasic()) return nullopt;
    return vc;
    }
}