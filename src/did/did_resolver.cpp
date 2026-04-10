#include "did_resolver.h"

namespace aic::ssi::did 
{

void DIDResolver::registerMethod(shared_ptr<DIDMethod> method) 
{
    if (!method) return;
    m_methods[method->methodName()] = move(method);
}

optional<DIDDocument> DIDResolver::resolve(const string& did) 
{
    auto parsed = DIDParser::parse(did);
    if (!parsed) return nullopt;

    auto it = m_methods.find(parsed->method);
    if (it == m_methods.end()) return nullopt;

    return it->second->resolve(did);
}

} // namespace aic::ssi::did