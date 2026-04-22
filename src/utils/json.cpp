#include "json.h"

namespace aic :: ssi :: utils 
{
    optional<nlohmann::json> Json :: parse(const string &raw)
    {
        if (raw.empty()) return nullopt; 

        try 
        {
            auto j = nlohmann :: json :: parse(raw); 
            return j; 
        } catch(...)
        {
            return nullopt; 
        }
    }

    string Json :: stringify(const nlohmann :: json &j, int indent)
    {
        try 
        {
            return j.dump(indent); 
        } catch(...)
        {
            return "{}"; 
        }
    }

    bool Json :: isObject(const nlohmann :: json &j)
    {
        return j.is_object(); 
    }

    bool Json :: isArray(const nlohmann::json &j)
    {
        return j.is_array(); 
    }
} // namespace aic :: ssi :: utils.