#include <optional>
#include <nlohmann/json.hpp>

using namespace std ; 

namespace aic :: ssi :: vc 
{
    struct VCProof 
    {
        string type; 
        string created; 
        string verificationMethod; 
        string proofPurpose; 
        string signature; 

        nlohmann :: json toJson() const; 
        static optional<VCProof> fromJson(const nlohmann :: json &j); 

        bool isValidBasic() const; 
    }; 
} // namespace aic :: ssi:: vc;