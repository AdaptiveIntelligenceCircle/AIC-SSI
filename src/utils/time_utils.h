#pragma once 
#include <string>
using namespace std; 

namespace aic :: ssi :: utils 
{
    // ISO 8601 time helper .. 
    // AIC principles : deterministic time format for audit chain.. 

    class TimeUtils 
    {
        public:
        static string nowISO8601UTC(); 
        // lexi cographic compare works for ISO 8601 UTC.. 
        static bool isExpired(const string &nowISO8601, const string &expirationISO8601); 
    }; 
} // namespace aic :: ssi :: utils 