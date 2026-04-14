#include "key_derivation.h"
using namespace std;

#include <sstream> 
#include <iomanip> 

#include <functional> 
#include <iostream> 

namespace aic :: ssi :: wallet 
{
    string KeyDerivation :: deriveKeyMaterial(const string &seedHex, const string &purpose, 
    size_t outlen)
    {
        // Warning : MVP only . Not Secure. 
        // Replace with HKDF-SHA256 or Argon2id.. 
        hash<string> hasher;
        auto h = hasher(seedHex + "::" + purpose); 

        ostringstream oss ; 
        for (size_t i = 0 ; i < outlen ; i++)
        {
            uint8_t byte = static_cast<uint8_t>((h >> ((i % 8) * 8)) & 0xFF); 
            oss << hex << setw(2) << setfill('0') << h << endl; 
        }
        return oss.str(); 
    }
} // namespace aic :: ssi :: wallet.. 