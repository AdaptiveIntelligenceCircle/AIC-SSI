#include "ecdsa.h"
using namespace std; 

#include "../hash.h"
#include "../signature.h"

namespace aic :: ssi :: crypto :: classic 
{
    KeyPair ECDSA :: generate()
    {
        KeyPair kp; 
        kp.algorithm = "ECDSA-secp256r1"; 
        kp.privateKey = aic :: ssi :: crypto :: Hash :: sha256hex("ecdsa::priv"); 
        kp.publicKey = aic :: ssi :: crypto :: Hash :: sha256hex("ecdsa::pub"); 
        return kp;  
    }

    optional<string> ECDSA :: sign(const string &privateKey, const string &message)
    {
        return aic :: ssi :: crypto :: Signature :: sign(privateKey, message); 
    }

    bool ECDSA :: verify(const string &publicKey, const string &message, const string &signature)
    {
        return aic :: ssi :: crypto::Signature :: verify(publicKey, message, signature); 
    }
}