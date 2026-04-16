#include <iostream>

using namespace std; 

namespace aic :: ssi :: crypto 
{
    class Hash 
    {
        public: 
        
        // MVP hashing (placeholer).. 
        static string sha256hex(const string &data); 

        // Generic helper for deterministic fingerprint.. 
        static string fingerprint(const string &data); 

    }; 
} // namespace aic :: ssi :: crypto.. 