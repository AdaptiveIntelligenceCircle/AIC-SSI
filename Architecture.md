# Architecture Overview - AIC-SSI

### High-Level Design
AIC-SSI is a decentralized, ethical-first Self-Sovereign Identity system built on top of AIC’s ethical kernel.

### Core Components
- **DID Engine**: Decentralized Identifiers with quantum-resistant keys
- **Verifiable Credentials (VC) Module**: Privacy-preserving credential issuance and verification
- **Ethical Wallet**: Self-custodial wallet integrated with IBCS (Introspective Behavioral Control System)
- **Recovery & Resilience Layer**: Backup mechanisms that respect user sovereignty
- **Integration Layer**: Native support for AIC-DePin, AIC-EdgeOS, and HMN

### Design Principles
- Ethical-from-Kernel: All identity operations are validated by IBCS
- Privacy by Default: Minimal data disclosure and zero-knowledge where possible
- No Central Authority: No trusted third party required
- Quantum-Safe: Future-proof cryptographic primitives

**Current Status (April 2026)**: Early architecture and prototype stage.