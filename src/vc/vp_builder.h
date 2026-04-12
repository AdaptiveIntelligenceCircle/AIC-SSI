#pragma once 
#include <string>
#include <vector> 

#include <optional>
#include <memory> 
using namespace std; 

#include "vp.h"
#include "vc_proof.h"

namespace aic :: ssi :: crypto 
{
    class CryptoProvider; 
}

namespace aic :: ssi :: vc 
{
    struct PresentationRequest
    {
        string holderDID; 
        vector<VerifiableCredential> credentials; 
        string verificationMethod; 
    };  

    class VPBuilder 
    {
        public:
        explicit VPBuilder(shared_ptr<aic::ssi::crypto:: CryptoProvider> &crypto);

        optional<VerifiablePresentation> build(const PresentationRequest &req); 

        private: 
        shared_ptr<aic::ssi::crypto::CryptoProvider> m_crypto; 
        
        string nowISO8601() const; 
        string makePresentationId(const string &holder) const;
        string canonicalizeForSigning(const VerifiablePresentation &vp) const;  

    }; 
} // namespace aic :: ssi :: vc  