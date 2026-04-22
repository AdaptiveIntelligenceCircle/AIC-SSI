# AIC-SSI Changelog

This file documents notable changes to the AIC-SSI project.

AIC-SSI is an ethical, quantum-safe oriented SSI framework under the Adaptive Intelligence Circle ecosystem.

It is designed with the "Third Path" principles: decentralization, human autonomy, and anti-coercion identity infrastructure.

All changes are documented under these categories:
- Added
- Changed
- Deprecated
- Removed
- Fixed
- Security

---

## [0.1.0] - 2026-04-10

### Added
- Initial project architecture and repository structure.
- DID module with DID parser, DID document model, DID registry, DID resolver.
- VC module skeleton with issuer/verifier/proof structures.
- Wallet module skeleton including keystore, backup manager, access control, derivation pipeline.
- Storage module with FileStorage, MemoryStorage, SQLite fallback storage, ObjectStore.
- Crypto module abstraction (CryptoProvider) with classic and PQC placeholders.
- Utils module (json, base64, uuid, time_utils, secure_memory).
- Policy documentation framework in `POLICIES/`.
- Governance and security policy docs.

### Changed
- Standardized naming conventions across modules (`aic::ssi::*` namespaces).
- Enforced modular separation: DID/VC/Wallet must not directly depend on each other without core glue.

### Security
- Explicit warning: cryptographic implementations are placeholders.
- Introduced SecureMemory wipe utilities for sensitive data.

---

## [Unreleased]

### Planned
- Full VC Issuer/Verifier with DID-based signature validation.
- Revocation registry implementation (status list / accumulator design).
- Wallet encryption-at-rest using AES-256-GCM or ChaCha20-Poly1305.
- Audit hash-chain event log.
- Distributed DID registry integration (DHT/IPFS optional).
- PQC backend integration (liboqs).

---