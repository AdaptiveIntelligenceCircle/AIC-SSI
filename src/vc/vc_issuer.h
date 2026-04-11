#pragma once 
#include <string>

#include <optional>
#include <memory> 
using namespace std; 

#include "vc.h"
#include "vc_schema.h"
#include "vc_proof.h"

namespace aic :: ssi :: crypto
{
    class CryptoProvider; 
}

namespace aic :: ssi :: vc 
{
    struct CredentialIssueRequest
    {
        string issuerDID; 
        string subjectDID; 

        string schemaId; 
        vector<string> types; 
        vector<string> contexts;

        nlohmann:: json claims; 

        string expirationDates; 

        // which key of issuer should be used.. 
        string verificationMethod; 
    };

    class VCIssuer 
    {
        public: 
        VCIssuer(shared_ptr<aic :: ssi :: crypto :: CryptoProvider> crypto, 
            shared_ptr<VCSchemaRegistry> schemas); 
        optional<VerifiableCredential> issue(const CredentialIssueRequest &req);

        private: 
        shared_ptr<aic :: ssi :: crypto :: CryptoProvider> m_crypto; 
        shared_ptr<VCSchemaRegistry> m_schemas; 

        string nowISO8601() const;
        string makeCredentialId(const CredentialIssueRequest &req) const; 
        
        string canonicalizeForSigning(const VerifiableCredential &vc); 
    }; 
}
