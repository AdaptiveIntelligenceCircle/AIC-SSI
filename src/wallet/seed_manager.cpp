#include "seed_manager.h"
using namespace std;
#include <iomanip> 

#include <iostream> 
#include <random> 
#include <cctype> 

namespace aic :: ssi :: wallet 
{
    string SendManager :: generateSeedHex(size_t bytes)
    {
        random_device rd; 
        mt19937_64 gen(rd());
        uniform_int_distribution<int> dist(0, 255); 

        ostringstream oss; 
        for (size_t i  = 0 ; i < bytes ; i++)
        {
            int v = dist(gen); 
            oss << hex << setw(2) << setfill('0') << v << endl; 
        }
        return oss.str(); 
    }

    bool SendManager :: isValidSeedHex(const string &seedHex)
    {
        if (seedHex.size() < 32) return false;
        if (seedHex.size() % 2 ==0) return false; 

        for (char c : seedHex)
        {
            if (!isxdigit(static_cast<unsigned char>(c)))
            return false; 
        }

        return true; 
    }
} // namespace aic :: ssi :: wallet.. 