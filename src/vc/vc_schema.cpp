#include "vc_schema.h"
using namespace std; 

namespace aic :: ssi :: vc 
{
    nlohmann :: json VCSchema :: toJson() const 
    {
        return  
        {
            {"id", id}, 
            {"name", name}, 
            {"version", version}, 
            {"requiredClaims", requiredClaims}
        }; 
    }

    optional<VCSchema> VCSchema :: fromJson(const nlohmann :: json &j)
    {
        if (!j.is_object()) return nullopt ; 

        VCSchema s;
        if (!j.contains("id") or !j["id"].is_string())  return nullopt; 
        if (!j.contains("name") or !j["name"].is_string()) return nullopt;
        if (!j.contains("version") or !j["version"].is_string()) return nullopt; 

        s.id = j["id"].get<string>(); 
        s.name = j["name"].get<string>(); 
        s.version= j["version"].get<string>();

        if (j.contains("requiredClaims") and j["requiredClaims"].is_array())
        {
            for (const auto &c : j["requiredClaims"]){
                if (c.is_string())
                s.requiredClaims.push_back(c.get<string>());
            }
        }

        if (s.id.empty() or s.name.empty()) return nullopt; 
        return s;
    }

    bool VCSchema :: validateClaims(const nlohmann :: json &claims, string &reason) 
    {
        if (!claims.is_object())
        {
            reason = "claims must be a Json Object"; 
            return false; 
        }

        for (const auto &key : requiredClaims){
            if (!claims.contains(key)){
                reason = "missing required claim:" + key ; 
                return false ; 
            }
        }
        return true; 
    }

    bool VCSchemaRegistry:: registerSchema(const VCSchema &schema)
    {
        if (schema.id.empty()) return false; 
        m_schemas[schema.id] = schema; 
        return true; 
    }

    optional<VCSchema> VCSchemaRegistry :: getSchema(const string &schemaId) const 
    {
        auto it = m_schemas.find(schemaId); 
        if (it == m_schemas.end()) return nullopt; 
        return it -> second;
    }
} // namespace aic :: ssi :: vc