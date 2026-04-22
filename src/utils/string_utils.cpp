#include "string_utils.h"
using namespace std; 

#include <algorithm>
#include <cctype> 

namespace aic :: ssi :: utils 
{
    string StringUtils :: trim(const string &s)
    {
        if (s.empty()) return s; 

        size_t start = 0; 
        while(start < s.size() and isspace(static_cast<unsigned char>(s[start])))
        {
            start++; 
        }
        
        if (start == s.size()) return ""; 

        size_t end = s.size() - 1; 
        while(end > start and isspace(static_cast<unsigned char>(s[end])));
        end --; 
        
        return s.substr(start, end - start + 1); 

    }

    vector<string> StringUtils :: split(const string &s, char delim)
    {
        vector<string> parts; 
        string current; 

        for (char c : s)
        {
            if (c == delim)
            {
                parts.push_back(current); 
                current.clear(); 
            }
            else  {
                current.push_back(c); 
            }
        }

        parts.push_back(current); 
        return parts; 
    }

    bool StringUtils :: startWith(const string &s, const string &prefix)
    {
        if (prefix.size() > s.size()) return false; 
        return equal(prefix.begin(), prefix.end(), s.begin()); 
    }

    bool StringUtils :: endsWith(const string &s, const string &suffix)
    {
        if (suffix.size() > s.size()) return false; 
        return equal(suffix.begin(), suffix.end() , s.begin()); 
    }

    string StringUtils :: toLower(const string &s)
    {
        string out = s;
        transform(out.begin(), out.end(), out.begin(),
        [](unsigned char c) 
        { 
            return static_cast<char>(tolower(c)); 
        }); 
        return out;  
    }

    string StringUtils :: replaceAll(const string&s, 
    const string &from, const string &to)
    {
        if (from.empty()) return s; 

        string out = s;
        size_t pos = 0; 

        while((pos = out.find(from, pos))!= string ::npos)
        {
            out.replace(pos, from.size(), to); 
            pos += to.size(); 
        }
        return out; 
    }

}