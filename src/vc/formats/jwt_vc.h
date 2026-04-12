#pragma once 
#include <string>

#include <optional>
using namespace std; 
#include "../vc.h"

namespace aic :: ssi :: vc :: formats 
{
    // MVP placeholder JWT encoder/decoder.. 
    // In real implemetation you integrate.. 
    class JWTVC 
    {
        public: 
        static optional<string> encode(const VerifiableCredential &vc) ;
        static optional<VerifiableCredential> decode(const string &token); 
    }; 
} // namespace aic :: ssi :: vc :: formats.. 