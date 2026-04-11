#pragma once 
#include <string> 
#include <unordered_map>
#include <optional> 
#include <nlohmann/json.hpp>

using namespace std; 

namespace aic :: ssi :: vc 
{
    struct VCSchema 
    {
        string id; 
        string name; 
        string version; 

        // required claim keys.. 
        vector<string> requiredClaims; 

        nlohmann :: json toJson() const; 
        static optional<VCSchema> fromJson(const nlohmann :: json &j); 

        bool validateClaims(const nlohmann :: json &claims, string &reason); 
        
    }; 

    class VCSchemaRegistry 
    {
        public: 
        bool registerSchema(const VCSchema &schema);
        
        optional<VCSchema> getSchema(const string &schemaId) const; 

        private:
        unordered_map<string, VCSchema> m_schemas; 
    }; 
} // namespace aic :: ssi :: vc 