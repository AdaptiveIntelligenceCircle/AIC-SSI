#include "storage_provider.h"
using namespace std; 
#include "object_store.h"

namespace aic :: ssi :: storage 
{
    ObjectStore :: ObjectStore(shared_ptr<StorageProvider> provider)
    {
        m_provider = move(provider); 
    }

    bool ObjectStore :: putJson(const string &key, const nlohmann :: json &obj)
    {
        if (!m_provider) return false; 
        return m_provider -> put(key, obj.dump(4)); 
    }

    optional<nlohmann :: json > ObjectStore :: getJson(const string &key)
    {
        if (!m_provider) return nullopt; 

        string raw; 
        if (!m_provider -> get(key, raw)) return nullopt; 

        try {
            return nlohmann :: json :: parse(raw); 
        } catch(...)
        {
            return nullopt;
        }
    }

    bool ObjectStore :: putText(const string &key, const string &text)
    {
        if (!m_provider) return false; 
        return m_provider -> put(key, text); 
    }

    optional<string> ObjectStore :: getText(const string &key)
    {
        if (!m_provider) return nullopt;
        string raw;

        if (!m_provider -> get(key, raw)) return nullopt;
        return raw; 
    }

    bool ObjectStore :: remove(const string &key)
    {
        if (!m_provider) return false; 
        return m_provider -> remove(key); 
    }
} // namespace aic :: ssi :: crypto