#pragma once 
#include <string> 

#include <vector>
#include <optional> 

#include <iostream>
using namespace std; 

namespace aic :: ssi :: utils 
{
    // Minimal Base64 encoding/decoding.. 
    // Used for wallet backup, VC proof encoding,.. etc.. 

    class Base64 
    {
        public: 
        static string encode(const string &data); 
        static string encode(const vector<uint8_t> &data); 

        static optional<string> decodeToString(const string &b64); 
        static optional<vector<uint8_t>> decodeToBytes(const string &b64); 
    }; 
} // namespace aic :: ssi :: utils..