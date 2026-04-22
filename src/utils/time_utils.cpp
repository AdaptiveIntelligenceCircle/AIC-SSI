#include "time_utils.h"
using namespace std; 

#include <chrono>
#include <sstream>

#include <iomanip>

namespace aic :: ssi :: utils 
{
    string TimeUtils :: nowISO8601UTC()
    {
        using namespace chrono; 

        auto now = system_clock :: now(); 
        auto tt = system_clock :: to_time_t(now); 

        tm tm{}; 

        #ifdef _WIN32
        gmtime_s(&tm, &tt);
        #else
        gmtime_r(&tt, &tm);
        #endif

        ostringstream oss; 
        oss << put_time(&tm, ""); 
        return oss.str(); 
    }

    bool TimeUtils :: isExpired(const string &nowISO8601, 
    const string &expirationISO8601) 
    {
        if (expirationISO8601.empty()) return false;
        return nowISO8601 >= expirationISO8601;
    }
} // namespace aic :: ssi :: utils.. 