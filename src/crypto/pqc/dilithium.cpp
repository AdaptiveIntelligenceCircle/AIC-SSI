#include "dilithium.h"
#include "../hash.h"
#include "../signature.h"

namespace aic::ssi::crypto::pqc 
{

KeyPair Dilithium::generate() 
{
    KeyPair kp;
    kp.algorithm = "Dilithium3";
    kp.privateKey = aic::ssi::crypto::Hash::sha256hex("dilithium::priv");
    kp.publicKey = aic::ssi::crypto::Hash::sha256hex("dilithium::pub");
    return kp;
}

optional<std::string> Dilithium::sign(const std::string& privateKey,
                                           const std::string& message) 
{
    return aic::ssi::crypto::Signature::sign(privateKey, message);
}

bool Dilithium::verify(const std::string& publicKey,
                       const std::string& message,
                       const std::string& signature) {
    return aic::ssi::crypto::Signature::verify(publicKey, message, signature);
}

} // namespace aic::ssi::crypto::pqc