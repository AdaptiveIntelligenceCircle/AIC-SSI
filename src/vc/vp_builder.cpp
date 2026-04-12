#include <iostream>
using namespace std; 
#include <sstream>

#include "vp_builder.h"
#include <chrono>
#include <iomanip>

namespace aic :: ssi :: vc 
{
    VPBuilder :: VPBuilder(shared_ptr<aic::ssi::crypto:: CryptoProvider> &crypto)
    {
        m_crypto = move(crypto); 
    }

    string VPBuilder :: nowISO8601() const 
    {
        using namespace chrono;
        auto now = system_clock:: now(); 

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

    string VPBuilder::makePresentationId(const string& holder) const 
    {
    auto ts = chrono::system_clock::now().time_since_epoch().count();

    ostringstream oss;
    oss << "urn:aic:vp:" << holder << ":" << ts;
    return oss.str();
    }

    string VPBuilder :: canonicalizeForSigning(const VerifiablePresentation &vp) const
    {
        auto j = vp.toJson(); 
        j.erase("proof");
        return j.dump();
    } 

    optional<VerifiablePresentation> VPBuilder :: build(const PresentationRequest &req)
    {
        if (!m_crypto) return nullopt; 
        if (req.holderDID.empty()) return nullopt;  

        VerifiablePresentation vp; 
        vp.id = makePresentationId(req.holderDID); 

        vp.holder = req.holderDID;
        vp.credentials = req.credentials;

        vp.contexts.push_back("https://www.w3.org/2018/credentials/v1");
        vp.types.push_back("VerifiablePresentation");

        VCProof proof; 
        proof.type = "AICSignature2026";
        proof.created = nowISO8601();
        proof.verificationMethod = req.verificationMethod.empty()
        ? (req.holderDID + "#key-1")
        : req.verificationMethod;
        proof.proofPurpose = "authentication";

        string msg = canonicalizeForSigning(vp);

    // auto sigOpt = m_crypto->sign(req.holderDID, msg);
    // if (!sigOpt.has_value()) return std::nullopt;

    // proof.signature = sigOpt.value();
    vp.proof = proof.toJson();

    if (!vp.isValidBasic()) return nullopt;
    return vp;
    }
}