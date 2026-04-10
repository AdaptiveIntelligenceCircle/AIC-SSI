#include "vc_proof.h"
using namespace std; 

namespace aic :: ssi :: vc 
{
    bool VCProof :: isValidBasic() const 
    {
        if (type.empty()) return false; 
        if (created.empty()) return false; 
        if(verificationMethod.empty()) return false; 

        if (proofPurpose.empty()) return false; 
        if (signature.empty()) return false;
        return true;
    }

    nlohmann :: json VCProof ::toJson() const 
    {
        return {
            {
                "type", type 
            }, 
            {

                "created", created
            },
            {
                "verificationMethod", verificationMethod
            }, 
            {
                "proofPurpose", proofPurpose
            }, 
            {
                "signature", signature
            }
        }; 
    }

    optional<VCProof> VCProof :: fromJson(const nlohmann :: json &j)
    {
        if (!j.is_object()) 
        return nullopt; 

        VCProof p;

        if (!j.contains("type") or !j["type"].is_string()) return nullopt; 
        if (!j.contains("created") || !j["created"].is_string()) return nullopt;
        if (!j.contains("verificationMethod") || !j["verificationMethod"].is_string()) return nullopt;
        if (!j.contains("proofPurpose") || !j["proofPurpose"].is_string()) return nullopt;
        if (!j.contains("signature") || !j["signature"].is_string()) return nullopt;

        p.type = j["type"].get<string>();
        p.created = j["created"].get<string>();
        p.verificationMethod = j["verificationMethod"].get<string>();
        p.proofPurpose = j["proofPurpose"].get<string>();
        p.signature = j["signature"].get<string>();

        if (!p.isValidBasic()) return nullopt;
        return p;
    }
}