#pragma once 
#include <string>

#include <iostream> 
using namespace std; 

#include "../keypair.h"

namespace aic :: ssi :: crypto :: classic 
{
    // placeholder Ed25519..
    // Real Ed25519

    class Ed25519 
    {
        public: 
        static KeyPair generate(); 

        static optional<string> sign(const string &privateKey, const string &message); 

        static bool verify(const string &publicKey, const string &message, const string &signature); 

    };  
}