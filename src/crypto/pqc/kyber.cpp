#include "kyber.h"
using namespace std; 

#include "../hash.h"
#include <iostream> 

namespace aic :: ssi :: crypto :: pqc 
{
    KeyPair Kyber :: generate()
    {
        KeyPair kp; 
        kp.algorithm = "Kyber768"; 
        kp.privateKey = aic :: ssi :: crypto :: Hash :: sha256hex("kyber::priv"); 
        kp.publicKey = aic :: ssi :: crypto :: Hash :: sha256hex("kyber::pub"); 

        return kp; 
    }

    optional<string> Kyber :: encapsulate(const string &publicKey)
    {
        if (publicKey.empty()) return nullopt; 
        return aic :: ssi :: crypto :: Hash :: sha256hex("Kyber::ct::" + publicKey);
    }

    optional<string> Kyber :: decapsulate(const string &privateKey, const string &ciphertext)
    {
        if (privateKey.empty() or ciphertext.empty()) return nullopt; 
        return aic :: ssi :: crypto :: Hash :: sha256hex("kyber::ss::" + privateKey + "::" + ciphertext);  
    }

} // namespace aic :: ssi :: crypto :: pqc