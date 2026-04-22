#include "base64.h"
using namespace std; 

namespace aic :: ssi :: utils 
{
    static const char *BASE64_CHARS = 
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/"; 

    static inline bool isBase64Char(unsigned char c)
    {
        return (isalnum(c) or (c == '+') or (c == '/')); 
    }

    string Base64 :: encode(const vector<uint8_t>&data)
    {
        string out; 
        int val = 0; 
        int valb = -6; 

        for (uint8_t c : data){
            val = (val << 8) + c;
            valb+= 8; 

            while(valb >= 0)
            {
                out.push_back(BASE64_CHARS[(val >> valb) & 0x3F]);
                valb -= 6;
            }
        }

        if (valb > -6)
        {
            out.push_back(BASE64_CHARS[((val << 8) >> (valb + 8)) & 0x3F]); 
        }
        while (out.size() % 4) out.push_back(
            '='
        ); 

        return out; 
    }

    string Base64 :: encode(const string &data)
    {
        return encode(vector<uint8_t>(data.begin(), data.end())); 
    }

    optional<vector<uint8_t>> Base64 :: decodeToBytes(const string &b64)
    {
        if (b64.empty()) return nullopt; 

        vector<int> T(256, -1); 

        for (int i = 0 ; i < 64 ; i++)
        {
            T[static_cast<unsigned char>(BASE64_CHARS[i])] = i; 
        }

        vector<uint8_t> out; 

        int val = 0; 
        int valb = -6; 

        for (unsigned char c : b64)
        {
            if (c == '=') break; 
            if (T[c] == -1) return nullopt; 

            val = (val << 6) + T[c]; 
            valb += 6; 

            if (valb >= 0)
            {
                out.push_back(static_cast<uint8_t> ((val >> valb)& 0xFF)); 
                valb -= 8; 
            }
        }
        return out; 
    }

    optional<string> Base64 :: decodeToString(const string &b64)
    {
        auto bytes = decodeToBytes(b64); 

        if (!bytes.has_value()) return nullopt; 

        return string(bytes -> begin(), bytes -> end());
    }
}