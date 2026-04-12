#pragma once
#include <string>
#include <optional>

#include "../vc.h"
using namespace std; 

namespace aic::ssi::vc::formats 
{

// JSON-LD adapter (MVP).
// Real JSON-LD normalization requires RDF dataset canonicalization.
// For now we treat it as a JSON export/import format.

class JSONLDVC 
{
public:
    static optional<std::string> serialize(const VerifiableCredential& vc);
    static optional<VerifiableCredential> deserialize(const std::string& raw);
};

} // namespace aic::ssi::vc::formats