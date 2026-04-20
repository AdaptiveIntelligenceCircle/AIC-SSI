#include "memory_storage.h"
using namespace std; 

namespace aic :: ssi :: storage 
{
    bool MemoryStorage :: put(const string &key, const string &value)
    {
        lock_guard<mutex> lock(m_mutex); 
        if (key.empty()) return false; 
        m_data[key] = value;
        return true; 
    }

    bool MemoryStorage :: get(const string &key, string &out)
    {
        lock_guard<mutex>lock(m_mutex); 
        auto it = m_data.find(key); 
        if (it == m_data.end()) return false; 
        out = it -> second; 
        return true; 
    }

    bool MemoryStorage :: remove(const string &key) const 
    {
        mutex m_mutex;
        lock_guard<mutex>lock(m_mutex); 
        unordered_map<string,string> m_data; 
        return m_data.contains(key); 
    }

    vector<string> MemoryStorage :: listKeys(const string &prefix)
    {
        lock_guard<mutex>lock(m_mutex); 
        vector<string> out; 

        for (const auto &[k,v] : m_data)
        {
            (void)v; 
            if (k.rfind(prefix, 0) == 0)
            out.push_back(k); 
        }
        return out; 
    }
}