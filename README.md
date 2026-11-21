<!-- # AIC-SSI – Self-Sovereign Identity

**Official Self-Sovereign Identity Layer** of  
**Adaptive Intelligence Circle (AIC) & Human Meaning Network (HMN)**

<p align="center">
  <img src="assets/AIC-SSI.png" alt="AIC Logo" width="1024" length = "1024"/>
</p>

### Vision

A governance-oriented exploration of self-sovereign identity,
human agency, trust, and institutional resilience
for a world of increasingly distributed and cross-border systems.

This repository is not an identity provider. This repository is not a government identity system. This repository is not a production-ready implementation.

Its purpose is to explore how identity, governance, and human agency may coexist within public-interest digital infrastructure.

### Core Principles
- **Self-sovereignty**: Identity belongs to the individual/node, not to any third party.
- **Ethical-by-design**: All identity operations are governed by the ethical kernel (IBCS).
- **Zero-donation & non-profit**: No financial incentives or external funding.
- **Privacy-first & quantum-safe**: Built for long-term resilience in a post-scarcity world.
- **GPLv3.0 licensed**: Full transparency and copyleft protection.

### Structure 
``` pgsql
AIC-SSI/
├── README.md                          # Trang chính + tầm nhìn SSI trong AIC
├── LICENSE                            # GPLv3.0
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── SECURITY.md
├── GOVERNANCE.md
├── POLICIES/
│   ├── ETHICAL-IDENTITY-POLICY.md     # Chính sách danh tính đạo đức
│   ├── ZERO-DONATION-POLICY.md        # (link hoặc copy từ repo Legal)
│   └── THIRD-PATH-PRINCIPLES.md
├── src/                               # Code chính
│   ├── core/                          # SSI Core Engine
│   ├── did/                           # Decentralized Identifier
│   ├── vc/                            # Verifiable Credentials
│   ├── wallet/                        # Ethical Wallet
│   └── crypto/                        # Quantum-safe + ethical crypto
├── tests/                             # Unit & integration tests
├── scripts/                           # Tools hỗ trợ
├── docs/                              # Tài liệu kỹ thuật
│   ├── architecture.md
│   └── integration-guide.md
├── examples/                          # Ví dụ sử dụng
├── ANNOUNCEMENTS/                     # Lưu thông báo
│   └── YYYY-MM-Status.md
├── HISTORY/
│   └── CHANGELOG.md
└── CONTACT.md 
``` 

### Key Features (in development)
- Decentralized Identifiers (DID)
- Verifiable Credentials (VC)
- Ethical Wallet & key management
- Integration with AIC-DePin and AIC-EdgeOS
- Quantum-resistant cryptographic primitives
- Recovery & resilience mechanisms for HMN

### Current Status (November 2026)
This repository is in early architecture and prototype stage.  

It will serve as one of the foundational layers to protect user/node autonomy. 

**Part of the larger AIC ecosystem**:  
[Adaptive Intelligence Circle](https://github.com/AdaptiveIntelligenceCircle)

**License**: GPLv3.0 with Ethical Use Addendum (see `/POLICIES`)

**Maintained by**: Nguyễn Đức Trí (Founder & Architect) -->

# AIC-SSI

**Exploring self-sovereign identity, human agency, and cross-border trust in the context of public-interest digital infrastructure.**

> This is not an identity provider.  
> This is not a government identity system.  
> This is not a production-ready implementation.  
> This is a careful, early-stage exploration.

**Status:** Early architecture and design exploration (updated November 2026)  
**Parent project:** [Adaptive Intelligence Circle](https://github.com/AdaptiveIntelligenceCircle)  
**Related:** Human Meaning Network (HMN), Parallel TestNet (Phase 0), AIC-DPG-Alignment

<p align="center">
  <img src="assets/AIC-SSI.png" alt="AIC Logo" width="1024" length = "1024"/>
</p>

---

## Purpose

AIC-SSI exists to explore how concepts from self-sovereign identity (SSI) might intersect with:

- Human agency and meaningful human control
- Ethical constraints near the point of authorization (Ethical-from-kernel)
- Resistance to capture by states, large platforms, or commercial interests (Third Path)
- Long-term resilience of identity-related assumptions in distributed systems

It is deliberately modest in scope and claims.

---

## What this repository is

- A place to document design questions, constraints, and trade-offs around identity and agency
- A space to explore how DID / VC-style ideas might (or might not) fit within AIC’s principles
- An attempt to keep identity-related thinking aligned with Non-Capture, Do No Harm, and under-claim discipline

## What this repository is not

- An identity service or issuer
- A replacement for national or organizational identity systems
- A claim that AIC has solved self-sovereign identity
- A production system or near-production prototype
- A guarantee of privacy, quantum-resistance, or cross-border legal recognition

---

## Core Orientation Principles

| Principle              | Meaning in this context                                      |
|------------------------|--------------------------------------------------------------|
| Human agency           | Identity-related mechanisms should not hollow out human judgment or responsibility |
| Ethical-from-kernel    | High-stakes identity operations should remain subject to fail-closed ethical evaluation where applicable |
| Non-capture            | Design should reduce, not increase, the risk of identity infrastructure becoming a control surface |
| Under-claim            | Prefer accurate limitation statements over impressive feature lists |
| Third Path             | Avoid structures that make the work easily capturable by pure state or pure commercial power |
| Zero-donation spirit   | Avoid funding or partnership models that create hidden influence over identity design |

---

## Current Status (November 2026)

- The repository remains in early architecture and conceptual exploration.
- No claim is made that core components are complete, audited, or ready for real-world reliance.
- Work in this repository is secondary to the progress and stability of Parallel TestNet Phase 0 and core ethical kernel development.
- Documentation and design clarity are currently prioritized over feature expansion.

Any future implementation work will be evaluated against the same under-claim and non-capture standards applied across the AIC ecosystem.

---

## Relationship to other AIC work

- **Parallel TestNet** — the primary place where governance and ethical evaluation ideas are tested
- **AIC-DPG-Alignment** — records how AIC relates to Digital Public Goods concepts
- **AIC-Legal / Governance materials** — broader policy and non-capture orientation
- **Human Meaning Network** — longer-term framing around meaning and human responsibility

SSI-related ideas here are exploratory inputs, not overriding architecture.

---

## Structure (high-level)

```text
AIC-SSI/
├── README.md
├── LICENSE
├── Code_of_Conduct.md
├── Contributing.md
├── Security.md
├── Governance.md
├── Roadmap.md
├── Architecture.md
├── docs/
│   ├── post-dpga-orientation.md
│   └── (additional design notes)
├── policies/
├── examples/          # illustrative only
├── src/               # early / experimental code (if any)
└── HISTORY/
```

**License**: GPLv3.0 with Ethical Use Addendum (see `/POLICIES`)

**Maintained by**: Nguyễn Đức Trí (Founder & Architect) -->

## Contributing 
See **CONTRIBUTING.md** 

We welcome careful, principle-aligned contributions that improve clarity and reduce the risk of over-claiming.

We do not seek rapid feature growth or productionization pressure in this repository.

**Adaptive Intelligence Circle**

Independent ethical coordination infrastructure — from Global South outward.

> Third Path. Ethical-from-kernel. Under-claim. Non-capture. Human agency.