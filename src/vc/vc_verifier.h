#pragma once 
#include <string>
#include <optional> 

#include <memory> 
using namespace std;
#include <iostream>  

#include "vc.h"
#include "vc_proof.h"
#include "revocation_registry.h"

namespace aic :: ssi :: crypto
{
    class CryptoProvider; 
}

namespace aic :: ssi :: did 
{
    class DIDResolver; 
    struct DIDDocument; 
}

namespace aic :: ssi :: vc 
{
    struct VerificationResult 
    {
        bool ok = false; 
        string reason; 
    }; 

    class VCVerfier 
    {
        public: 
        VCVerfier(shared_ptr<aic::ssi::crypto::CryptoProvider> crypto,
        shared_ptr<aic::ssi::did::DIDResolver> resolver);
    }; 
}