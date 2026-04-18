#include "ed25519.h"
using namespace std;

#include "../hash.h"
#include "../signature.h"

namespace aic :: ssi :: crypto :: classic 
{
    KeyPair Ed25519 :: generate()
    {
        KeyPair kp; 
        kp.algorithm = "Ed25519"; 
        kp.privateKey = aic :: ssi :: crypto :: Hash :: sha256hex("ed25519::priv"); 
        kp.publicKey = aic :: ssi :: crypto :: Hash :: sha256hex("ed25519:: pub"); 
        return kp; 
    }

    optional<string> Ed25519:: sign(const string &privateKey, const string &message)
    {
        return aic :: ssi :: crypto :: Signature :: sign(privateKey, message);
    }

    bool Ed25519 :: verify(const string &publicKey, 
    const string &message, const string &signature )
    {
        return aic :: ssi :: crypto :: Signature ::verify(publicKey, message, signature);  
    }
} // namespace aic :: ssi :: crypto :: classic 