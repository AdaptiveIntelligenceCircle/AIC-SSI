#pragma once 
#include <memory>

#include "../did_method.h"
#include "../did_registry.h"

using namespace std; 
#include <iostream>

namespace aic :: ssi:: did 
{
    class DIDAICMethod : public DIDMethod
    {
        public:
        explicit DIDAICMethod (shared_ptr<DIDRegistry> registry); 

        string methodName() const override; 

        optional<DIDDocument> 
        create(const DIDCreateRequest &req)override; 

        optional<DIDDocument> resolve(const string &did) override; 

        private:
        shared_ptr<DIDRegistry> m_registry; 

        string nowISO8601() const;
        string generateDID(const DIDCreateRequest &req) const; 
    };
} // namespace aic :: ssi :: did..