#pragma once 
#include <iostream>
using namespace std; 

#include "did_parser.h"

namespace aic :: ssi :: did 
{
    optional<DID> DIDParser:: parse(const string &did) 
    {
        // DID format : did <method>:<id> 
        if (did.size() < 8) return nullopt; 
        if (did.rfind("did:", 0) != 0) return nullopt; 

        auto pos1 = did.find(':', 4);
        if (pos1 == string :: npos) return nullopt; 

        string method = did.substr(4, pos1 -4);
        if (method.empty()) return nullopt; 

        string id = did.substr(pos1 + 1); 
        if (id.empty()) return nullopt; 

        DID out; 
        out.full = did; 
        out.method = method; 
        out.id = id; 
        return out; 
    }

    bool DIDParser ::isValid(const string &did)
    {
        return parse(did).has_value(); 
    }
}