#include "jsonld_vc.h"

namespace aic::ssi::vc::formats 
{

optional<string> JSONLDVC::serialize(const VerifiableCredential& vc) 
{
    return vc.toJson().dump(4);
}

optional<VerifiableCredential> JSONLDVC::deserialize(const string& raw) 
{
    try {
        auto j = nlohmann::json::parse(raw);
        return VerifiableCredential::fromJson(j);
    } catch (...) {
        return nullopt;
    }
}

} // namespace aic::ssi::vc::formats