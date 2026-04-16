#pragma once 
#include <string> 

#include <optional>
using namespace std; 

namespace aic :: ssi :: crypto 
{
    // Symmetric encryption wrapper..
    // MVP : XOR based placeholder.. 
    // Replace with AES256GCM ...

    class SymmetricCrypto 
    {
        public: 
        static optional<string> encrypt(const string &key, const string &plaintext); 

        static optional<string> decrypt(const string &key, const string &ciphertext); 

        private: 
        static string xorTransform(const string &key, const string &data); 
    }; 
} // namespace aic :: ssi :: crypto.