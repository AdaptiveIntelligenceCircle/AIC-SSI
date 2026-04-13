#pragma once 
#include <string> 

using namespace std; 

namespace aic :: ssi :: wallet 
{
    // Access control is lightweight layer.. 
    // Later it will integrate with AIC policy Engine.. 
    enum class WalletPermission 
    {
        UnlockWallet, 
        ExportKeys, 
        ImportKeys, 
        SignData, 
        StoreCredential, 
        LoadCredential, 
        BackupWallet, 
        RestoreWallet 
    }; 

    struct AccessDecision 
    {
        bool allowed = false; 
        string reason; 
    }; 

    class AccessControl 
    {
        public: 
        virtual ~AccessControl() = default; 

        virtual AccessDecision check(WalletPermission perm, const string &actor, const string &context);
    }; 

    // Default permissive access control for MVP..
    // Later you can replace by policy module.. 
    class DefaultAccessControl : public AccessControl
    {
        public: 
        AccessDecision check(WalletPermission perm, 
        const string &actor, const string &context) override
        {
            (void)perm;
            (void)actor; 
            (void)context; 
            return 
            {
                true, "default allow"
            }; 
        }

    }; 
} // namespace aic :: ssi :: wallet