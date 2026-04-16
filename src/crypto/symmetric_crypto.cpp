#include "symmetric_crypto.h"
#include "hash.h"
using namespace std; 

namespace aic :: ssi :: crypto 
{
    string SymmetricCrypto :: xorTransform(const string &key, const string &data)
    {
        string derived = Hash :: sha256hex(key); 

        string out = data; 

        for (size_t i = 0;  i< out.size(); i++)
        {
            out[i] = static_cast<char>(out[i] ^ derived[i % derived.size()]); 
        }
        return out; 
    }

    optional<string> SymmetricCrypto :: encrypt(const string &key, const string &plaintext)
    {
        if (key.empty()) return nullopt;
        return xorTransform(key, plaintext); 
    }

    optional<string> SymmetricCrypto :: decrypt(const string &key, const string &ciphertext)
    {
        if (key.empty()) return nullopt; 
        return xorTransform(key, ciphertext); 
    }
}