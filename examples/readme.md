# AIC-SSI Examples

This folder contains minimal end-to-end examples demonstrating how to use AIC-SSI modules.

All examples are designed for:
- clarity
- audit-friendly flow
- deterministic behavior
- modular integration

## Available Examples

### 1. DID Create and Resolve
File: `did_create_and_resolve.cpp`

Shows:
- generating a DID Document
- storing it in registry
- resolving DID back into DID Document

### 2. Wallet Create and Backup
File: `wallet_create_and_backup.cpp`

Shows:
- creating a wallet profile
- storing a keypair
- exporting wallet backup
- importing wallet backup

### 3. VC Issue and Verify
File: `vc_issue_and_verify.cpp`

Shows:
- creating an issuer DID
- issuing a VC JSON
- verifying VC signature

### 4. VP Build and Verify
File: `vp_build_and_verify.cpp`

Shows:
- collecting VC into a Verifiable Presentation
- signing VP
- verifying VP

### 5. Revocation Demo
File: `revocation_demo.cpp`

Shows:
- issuing a VC
- revoking the VC
- verifying that VC becomes invalid

---

## Build Instructions

If using CMake:
```bash
mkdir build
cd build
cmake ..
make