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
}