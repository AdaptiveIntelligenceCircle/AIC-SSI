#include "vp.h"
using namespace std; 

namespace aic :: ssi :: vc 
{
    bool VerifiablePresentation :: isValidBasic() const 
    {
        if (id.empty()) return false; 
        if (holder.empty()) return false; 
        if (types.empty()) return false; 
        if (contexts.empty()) return false; 

        return true; 
    }

    nlohmann :: json VerifiablePresentation :: toJson() const 
    {
        nlohmann :: json j; 

        j["id"]  = id; 
        j["holder"] = holder; 
        j["@context"] = contexts; 
        j["type"] = types; 

        j["verifiableCredential"] = nlohmann :: json :: array(); 

        for (const auto &vc : credentials)
        {
            j["verifiableCredential"].push_back(vc.toJson()); 
        }

        if (!proof.is_null() and !proof.empty())
        j["proof"] = proof;
        
        return j; 
    }

    optional<VerifiablePresentation> VerifiablePresentation :: fromJson(const nlohmann :: json &j)
    {
        if (!j.is_object()) return nullopt; 

        VerifiablePresentation vp; 

        if (!j.contains("id") or !j["id"].is_string()) return nullopt; 
        if (!j.contains("holder") or !j["holder"].is_string()) return nullopt; 

        vp.id = j["id"].get<string>(); 
        vp.holder = j["holder"].get<string>(); 

        if (!j.contains("@context") or !j["@context"].is_array()) 
        return nullopt; 
        
        for (const auto &c : j["@Context"])
        {
            if (c.is_string())
            vp.contexts.push_back(c.get<string>()); 
            // contexts
        }

        if (!j.contains("type") or !j["type"].is_array()) return nullopt;
        for (const auto &t : j["type"])
        {
            if (t.is_string())
            vp.types.push_back(t.get<string>()); 
        }

        if (!j.contains("verifiableCredential") and j["verifiableCredential"])
        {
            for (const auto &item: j["verifiableCredential"])
            {
                auto vcOpt = VerifiableCredential :: fromJson(item); 
                if (vcOpt) 
                vp.credentials.push_back(*vcOpt); 
            }
        }

        if (j.contains("proof") and j["proof"].is_object())
        vp.proof = j["proof"]; 

        if (!vp.isValidBasic()) return nullopt;

        return vp; 
    }
} // namespace aic :: ssi :: vc 