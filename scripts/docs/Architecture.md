# AIC-SSI scripts architecture.

In AIC-SSI, the **`scripts/`** folder shouldn't be just a "mess of shell stuff," but should serve as a **tooling layer**: build, test, lint, generate DID/VC, audit check, export wallet, simulate attack, publish release.

---

## ✅ `scripts/` Structure

```
scripts/
├── build.sh
├── build.ps1
├── run_tests.sh
├── run_tests.ps1
├── format.sh
├── lint.sh
├── clean.sh
├── setup_dev_env.sh
├── generate_did.sh
├── issue_vc.sh
├── verify_vc.sh
├── wallet_export.sh
├── wallet_import.sh
├── audit_check.sh
├── revocation_update.sh
├── benchmark_crypto.sh
├── simulate_attack.sh
├── publish_release.sh
└── tools/

├── json_validate.py

├── keygen.py

├── did_resolve.py

├── vc_issue.py

├── vc_verify.py

├── vp_build.py

└── revocation_tool.py
```

---
## Explanation of the meaning of each file

### **Build & Run**

* `build.sh` / `build.ps1` 
Build project (CMake or g++ directly).
* `clean.sh` 
Delete build artifacts.
* `setup_dev_env.sh` 
Setup dependencies: `nlohmann/json`, compiler flags, etc.

---

### **Test**

* `run_tests.sh` / `run_tests.ps1` 
Run unit tests + integration tests.
* `benchmark_crypto.sh` 
Benchmark signing/encryption performance.

---

### **Code Quality**

* `format.sh` 
run `clang-format` in style.
* `lint.sh` 
run `clang-tidy` (if available).

---

### **SSI Workflow (DID/VC/Wallet)**

* `generate_did.sh` 
create DID + DID Document.
* `issue_vc.sh` 
issue credential.
* `verify_vc.sh` 
verify credential.
* `wallet_export.sh` 
export wallet backup.
* `wallet_import.sh` 
import wallet backup.

---

### **Security / Audit / Revocation**

* `audit_check.sh` 
check integrity log / hash chain.
* `revocation_update.sh` 
revoke a VC or update the revocation registry.
* `simulate_attack.sh` 
Simulate cases: forged VC, replay attack, fake DID.

---

### **Release**

* `publish_release.sh` 
package release artifact + generate changelog snapshot.

---

## Folder `scripts/tools/` for quick CLI tool generation

The Python files in `tools/` aim to:

* test SSI pipeline without building the UI
* generate sample JSON
* validate schema
* run automation

---

## Minimum Required Files (MVP)

If you want to keep your scripts concise, the minimum should include:

```
scripts/
├── build.sh
├── run_tests.sh
├── generate_did.sh
├── issue_vc.sh
├── verify_vc.sh
├── audit_check.sh
└── tools/

├── did_resolve.py

├── vc_issue.py
└── vc_verify.py
```

---