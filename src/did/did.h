#pragma once 
#include <string> 

using namespace std;

namespace aic :: ssi :: did 
{
    struct DID
    {
        string full; // "did : aic:user:xxxx"
        string method; // "aic"
        string id; // user : xxxx

        bool empty() const 
        {
            return full.empty(); 
        }
    }; 
}