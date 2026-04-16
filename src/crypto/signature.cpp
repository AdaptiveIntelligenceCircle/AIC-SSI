#include "signature.h"
#include "hash.h"
using namespace std; 
#include <iostream>

namespace aic :: ssi :: crypto 
{
    optional<string> Signature :: sign(const string &privateKeyraw, const string &message )
    {
        if (privateKeyraw.empty()) return nullopt; 
        return Hash :: sha256hex("sig::" + privateKeyraw+ "::" + message); 
    }

    bool Signature :: verify(const string &publicKeyRaw, 
    const string &message, const string &signature)
    {
        // MVP : cannot truly verify without real crypto.. 
        // We simulate by expecting signature = hash(pubKey + message).. 
        if (publicKeyRaw.empty()) return false; 
        auto expected = Hash :: sha256hex("sig::" + publicKeyRaw + "::" + message); 
        return expected == signature; 
    }
} // namespace aic :: ssi :: crypto. 