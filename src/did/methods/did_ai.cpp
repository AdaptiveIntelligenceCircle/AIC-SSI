#include "did_aic.h"
using namespace std; 

#include <chrono>
#include <sstream> 

#include <iomanip>
#include <iostream>

namespace aic :: ssi :: did 
{
    DIDAICMethod :: DIDAICMethod(shared_ptr<DIDRegistry> registry)
    {
        m_registry = move(registry); 
    }

    string DIDAICMethod :: methodName() const 
    {
        return "aic"; 
    }

    string DIDAICMethod :: nowISO8601() const 
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

    string DIDAICMethod :: generateDID(const DIDCreateRequest &req) const  
    {
        // Minimal deterministic-ish DID generation (placeholer)..
        // Later: hash(publicKey + timestamp + random salt).. 
        auto ts = chrono :: system_clock ::now().time_since_epoch().count(); 

        ostringstream oss;
        oss << "did:: Aic" << req.type << ":" << ts;
        return oss.str(); 
    }

    optional<DIDDocument> DIDAICMethod :: create(const DIDCreateRequest &req)
    {
        if (!m_registry) return nullopt;
        if (req.type.empty()) return nullopt; 
        if (req.publicKey.empty()) return nullopt;
        if (req.keyType.empty()) return nullopt;

        DIDDocument doc;
        doc.id = generateDID(req);
        doc.created = nowISO8601(); 
        doc.updated = doc.created; 
        
        VerificationMethod vm;
        vm.id = doc.id + "#key-1";
        vm.type = req.keyType ; 
        vm.controller = doc.id;
        vm.publickey = req.publicKey;

        doc.verificationMethods.push_back(vm); 

        // optional serive ouput..
        if (!req.hint.empty())
        {
            ServiceEndpoint se;
            se.id = doc.id + "#Service-1";
            se.type = "AICHint"; 
            se.endpoint = req.hint; 
            doc.services.push_back(se);  
        }

        if (!doc.isValidBasic())
        return nullopt; 

        if (!m_registry -> store(doc)) return nullopt; 

        return doc; 
    }

    optional<DIDDocument> DIDAICMethod:: resolve(const string &did)
    {
        if (!m_registry) return nullopt; 
        return m_registry -> load(did);     
    }
} // namespace aic :: ssi :: did 