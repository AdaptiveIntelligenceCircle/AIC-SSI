#pragma once 
#include <string> 

#include <optional> 
using namespace std; 

namespace aic :: ssi :: wallet 
{
    // SeedManager handles master seed generation and validations.. 
    // MVP : random string seed, 
    // Later: BIP39 mnemonic.. 
    class SendManager
    {
        public:
        static string generateSeedHex(size_t bytes = 32);
        static bool isValidSeedHex(const string& seedHex);
    }; 
}