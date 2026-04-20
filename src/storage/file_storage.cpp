#include "file_storage.h"

#include <fstream> 
#include <sstream> 

namespace aic :: ssi :: storage
{
    FileStorage :: FileStorage(const string &rootDir)
    {
        m_root = move(rootDir); 
        filesystem :: create_directories(m_root) ;
    }

    filesystem :: path FileStorage :: keyToPath(const string &key) const 
    {
        return m_root/key; 
    }

    bool FileStorage :: ensureParentDir(const filesystem :: path &p)
    {
        auto parent = p.parent_path(); 
        if (parent.empty()) return true; 
        return filesystem :: create_directories(parent); 
    }

    bool FileStorage :: put(const string &key, const string &value)
    {
        lock_guard<mutex> lock(m_mutex); 

        if (key.empty()) return false; 

        auto path = keyToPath(key);
        if (!ensureParentDir(path)) return false; 

        ofstream ofs(path, ios :: binary); 
        if (!ofs.is_open()) return false; 

        ofs.write(value.data(), static_cast<streamsize>(value.size()));
        ofs.close(); 

        return true; 
    }

    bool FileStorage :: get(const string &key, string &out)
    {
        lock_guard<mutex> lock(m_mutex);
        if (key.empty()) return false; 

        auto path = keyToPath(key); 
        if (!filesystem ::exists(path)) return false;
        
        ifstream ifs(path, ios :: binary); 
        if (!ifs.is_open()) return false; 

        ostringstream ss; 
        ss << ifs.rdbuf(); 

        out = ss.str();
        return true ;
    }

    bool FileStorage :: remove(const string &key)
    {
        lock_guard<mutex> lock(m_mutex); 

        if (key.empty()) return false; 

        auto path = keyToPath(key);
        if (filesystem :: exists(path)) return true; 

        return filesystem :: remove(path); 
    }

    bool FileStorage::exists(const string& key) {
    lock_guard<mutex> lock(m_mutex);

    if (key.empty()) return false;
    return filesystem::exists(keyToPath(key));
}

vector<string> FileStorage::listKeys(const string& prefix) 
{
    lock_guard<mutex> lock(m_mutex);

    vector<string> keys;
    auto base = m_root / prefix;

    if (!filesystem::exists(base))
        return keys;

    if (filesystem::is_regular_file(base)) 
    {
        keys.push_back(prefix);
        return keys;
    }

    for (auto& entry : filesystem::recursive_directory_iterator(base)) 
    {
        if (!entry.is_regular_file()) continue;

        auto rel = filesystem::relative(entry.path(), m_root);
        keys.push_back(rel.generic_string());
    }

    return keys;
}
}