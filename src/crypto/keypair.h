#pragma once 
#include <string> 

#include <iostream> 
using namespace std; 

namespace aic :: ssi :: crypto 
{
    struct KeyPair 
    {
        string algorithm; // ED22519, ECDSA, Dilithium....//
        string publicKey; // encoded
        string privateKey; // encoded (must be protected by wallet).. 
    };  
} // namespace aic :: ssi :: crypto.