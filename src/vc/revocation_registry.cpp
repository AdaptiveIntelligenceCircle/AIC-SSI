#include "revocation_registry.h"
using namespace std; 

#include <string>
#include <cmath>

#include <nlohmann/json.hpp>
#include <algorithm>

namespace aic :: ssi :: vc 
{
    RevocationRegistry :: RevocationRegistry(shared_ptr<aic :: ssi :: storage :: StorageProvider> storage)
    {
        m_storage = move(storage) ;
    }

    optional<string>RevocationRegistry :: readRaw()
    {
        if (!m_storage) return nullopt; 
        string raw; 

        //if (!m_storage -> get(m_storageKey , raw)) return nullopt; 
        return raw;
    }

    bool RevocationRegistry :: load()
    {
        m_revoked.clear();

        auto raw = readRaw(); 

        if (!raw) return true; // empty registry is ok// 

        try 
        {
            auto j = nlohmann:: json :: parse(*raw);
            if (!j.is_object()) return false; 

            if (j.contains("revoked") and j["revoked"].is_array())
            {
                for (const auto &id : j["revoked"])
                {
                    if (id.is_string())
                    m_revoked.insert(id.get<string>()); 
                }
            }

            return true; 
        } catch (exception &e)
        {
            return false; 
        }
    }

    bool RevocationRegistry :: save()
    {
        if (!m_storage) return false; 

        nlohmann :: json j; 
        j["revoked"] = nlohmann :: json :: array();

        for (const auto &id : m_revoked)
        {
            j["revoked"].push_back(id); 
        }
    }

    bool RevocationRegistry :: revoke(const string &credentialId, const string &reason)
    {
        (void)reason; 

        if (credentialId.empty()) return false;
        m_revoked.insert(credentialId); 
        return save(); 
    }    

    bool RevocationRegistry :: isRevoked(const string &credentialId)
    {
        if (credentialId.empty()) return false;
        return m_revoked.contains(credentialId);
    }
} // namespace aic :: ssi :: vc 