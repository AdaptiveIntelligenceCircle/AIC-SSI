#include "ipfs_storage.h"
using namespace std; 

namespace aic :: ssi :: storage :: distributed 
{
    IPFSStorage :: IPFSStorage(const string &getawayUrl)
    {
        m_gateway = getawayUrl; 
    }

    bool IPFSStorage :: put(const string &key, const string &value)
    {
        (void)key;
        (void)value; 

        // Todo :: implement real IPFS push/pin.. 
        return false; 
    }

    bool IPFSStorage :: get(const string &key, string &out)
    {
        (void)key; 
        (void)out; 

        // Todo :: implement real IPFS fetch.. 
        return false; 
    }

    bool IPFSStorage :: remove(const string &key)
    {
        (void)key; 
        return false; 
    }

    bool IPFSStorage :: exists(const string &key) 
    {
        (void)key; 
        return false; 
    }

    vector<string> IPFSStorage :: listKeys(const string &prefix)
    {
        (void)prefix; 
        return {}; 
    }
}