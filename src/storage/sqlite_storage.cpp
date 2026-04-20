#include "sqlite_storage.h"
#include "file_storage.h"

namespace aic :: ssi :: storage 
{
    SQLiteStorage :: SQLiteStorage(const string &dbPath)
    {
        m_dbPath = move(dbPath); 
    }

    bool SQLiteStorage :: put(const string &key, const string &value)
    {
        // MVP Fallback : store in file - like layout under dbPath directory.. 
        FileStorage fallback(m_dbPath + "_sqlite_fallback"); 
        return fallback.put(key, value); 
    }

    bool SQLiteStorage::get(const string& key, string& out) 
    {
        FileStorage fallback(m_dbPath + "_sqlite_fallback");
        return fallback.get(key, out);
    }

    bool SQLiteStorage::remove(const string& key) 
    {
        FileStorage fallback(m_dbPath + "_sqlite_fallback");
        return fallback.remove(key);
    }

    bool SQLiteStorage::exists(const string& key) 
    {
        FileStorage fallback(m_dbPath + "_sqlite_fallback");
        return fallback.exists(key);
    }

    vector<string> SQLiteStorage::listKeys(const string& prefix) 
    {
        FileStorage fallback(m_dbPath + "_sqlite_fallback");
        return fallback.listKeys(prefix);
    }
}