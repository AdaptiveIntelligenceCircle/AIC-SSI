#pragma once 
#include <string>
#include <optional>
using namespace std;

namespace aic :: ssi :: wallet 
{
    // Derive deterministic key material from seed.. 
    // MVP : naive derivation 
    // Replace with HKDF / PBKDF2 / Argon2 later..

    class KeyDerivation 
    {
        public: 
        static string deriveKeyMaterial(const string &seedHex, const string &purpose, 
        size_t outlen = 32); 
    }; 
} // namespace aic :: ssi :: wallset..