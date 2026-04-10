#include "did_registry.h"
#include "../storage/storage_provider.h"

using namespace std;

namespace aic :: ssi :: did 
{
    DIDRegistry ::DIDRegistry(shared_ptr<aic::ssi:: storage::StorageProvider> storage) 
    {
        m_storage = move(storage); 
    }

    string DIDRegistry :: makeKey(const string &did) const 
    {
        return "did_registry/" + did; 
    }

    bool DIDRegistry :: store(const DIDDocument &doc)
    {
        if (!m_storage) return false; 
        if (!doc.isValidBasic()) return false;

        auto key = makeKey(doc.id); 
        auto value = doc.toJson().dump(4); 
        // return m_storage -> put(key, value); 
    }

    optional<DIDDocument> DIDRegistry :: load(const string &did)
    {
        if (!m_storage) return nullopt; 

        string raw; 
        // if (!m_storage -> get(makeKey(did), raw)) return nullopt; 
        try 
        {
            auto j = nlohmann:: json:: parse(raw); 
            return DIDDocument :: fromJson(j);
        } catch(...)
        {
            return nullopt; 
        }
    }

    bool DIDRegistry :: exists(const string &did)
    {
        return load(did).has_value();
    }

    bool DIDRegistry :: remove(const string &did)
    {
        if (!m_storage) return false; 
        //return m_storage -> remove(makeKey(did));
    }

}