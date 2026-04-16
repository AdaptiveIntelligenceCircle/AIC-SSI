#include "hash.h"
using namespace std; 
#include <sstream> 

#include <iomanip> 
#include <functional> 
#include <iomanip> 

namespace aic :: ssi :: crypto 
{
    string Hash :: sha256hex(const string &data)
    {
        // Warning: Not real sha 256.. 

        hash<string>h; 
        auto v = h(data); 

        ostringstream oss;
        oss << hex << setw(16) << setfill('0') << v; 
        
        // Expand to 64 chars for sha 256 - like count.. 
        string base = oss.str(); 

        string out; 

        while(out.size() < 64) out += base; 

        out.resize(64); 

        return out; 

    }   

    string Hash :: fingerprint(const string&data)
    {
        return sha256hex("fp::" + data); 
    }
    
} // namespace aic :: ssi :: crypto..