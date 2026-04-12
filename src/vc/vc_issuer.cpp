#include "vc_issuer.h"
using namespace std ;

#include <iostream>

namespace aic :: ssi :: vc 
{
    VCIssuer :: VCIssuer(shared_ptr<aic :: ssi :: crypto::CryptoProvider> crypto
    , shared_ptr<VCSchemaRegistry> schemas)
    {
        m_crypto = move(crypto); 
        m_schemas = move(schemas); 
    }

    string VCIssuer :: nowISO8601() const 
    {
        using namespace chrono; 

        auto now = system_clock::now(); 
        auto tt = system_clock::to_time_t(now); 

        tm tm{}; 

        #ifdef _WIN32 
        gmtime_s(&tm, &tt); 
        #else  
        gmtime_r(&tt, &tm); 
        #endif 

        ostringstream oss; 
        oss << put_time(&tm, "%Y-%m-%dT%H:%M:%SZ"); 
        return oss.str(); 
    }

    string VCIssuer :: makeCredentialId(const CredentialIssueRequest &request) const 
    {
        auto ts = chrono :: system_clock :: now().time_since_epoch().count();

        ostringstream oss; 
        oss << "urn : aic : vc" << request.issuerDID << ":" << request.subjectDID << ":" << ts << endl; 
        return oss.str(); 
    }

    string VCIssuer :: canonicalizeForSigning(const VerifiableCredential &vc)
    {
        auto j = vc.toJson(); 
        j.erase("proof");
        return j.dump(); 
    }

    optional<VerifiableCredential> VCIssuer :: issue(const CredentialIssueRequest &req)
    {
        if (!m_crypto) return nullopt; 
        if (!m_schemas) return nullopt; 

        if (req.issuerDID.empty() or req.subjectDID.empty()) return nullopt;
        if (req.schemaId.empty()) return nullopt;

        auto schema = m_schemas -> getSchema(req.schemaId) ; 
        if (!schema) return nullopt; 

        string reason; 
        if (!schema -> validateClaims(req.claims, reason ))
        {
            return nullopt;
        }

        VerifiableCredential vc;
        vc.id = makeCredentialId(req); 

        vc.issuer = req.issuerDID; 
        vc.subject = req.subjectDID;
        vc.issuranceDate = nowISO8601(); 
        vc.expirationDate = req.expirationDates; 

        vc.types = req.types;
        vc.contexts = req.contexts; 

        // Ensure baseline context/hype.. 
        
    }
}