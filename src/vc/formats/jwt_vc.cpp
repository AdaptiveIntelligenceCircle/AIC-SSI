#include "jwt_vc.h"
using namespace std; 

namespace aic :: ssi :: vc :: formats 
{
    optional<string> JWTVC :: encode(const VerifiableCredential &vc)
    {
        // MVP : not real JWT, just JSON string with prefix.. 
        // This is a placeholder for future.. JWT standardization.. 
        return string("JWT Placeholder") + vc.toJson().dump(); 
    }

    optional<VerifiableCredential> JWTVC :: decode(const string &token)
    {
        const string prefix = "JWT_Placeholer"; 
        if (token.rfind(prefix, 0) != 0) return nullopt; 

        string raw = token.substr(prefix.size()); 

        try 
        {
            auto j = nlohmann:: json :: parse(raw); 
            return VerifiableCredential :: fromJson(j); 
        } catch(...)
        {
            return nullopt; 
        }
    }
}