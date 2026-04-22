#pragma once 
#include <string>
#include <vector>

using namespace std; 

namespace aic :: ssi :: utils 
{
    class StringUtils 
    {
        public: 
        static string trim(const string &s); 

        static vector<string> split(const string &s, char delim);
        
        static bool startWith(const string &s, const string &prefix);
        static bool endsWith(const string &s, const string &suffix); 

        static string toLower(const string &s); 
        static string toUpper(const string &s); 

        static string replaceAll(const string &s, const string &from, const string &to); 
    }; 
} // namespace aic :: ssi :: utils.. 