#!/usr/bin/env python3
import json
import argparse
import hashlib
import sys


def fake_hash(s: str) -> str:
    return hashlib.sha256(s.encode("utf-8")).hexdigest()


def is_valid_did(did: str) -> bool:
    if not isinstance(did, str):
        return False
    if not did.startswith("did:"):
        return False
    parts = did.split(":")
    if len(parts) < 3:
        return False
    if not parts[1]:
        return False
    if not parts[2]:
        return False
    return True


def sign_stub(private_key: str, payload: str) -> str:
    return fake_hash("sig::" + private_key + "::" + payload)


def verify_vc(vc: dict, audit_only=False) -> bool:
    if "issuer" not in vc:
        print("[FAIL] VC missing issuer")
        return False

    if "credentialSubject" not in vc:
        print("[FAIL] VC missing credentialSubject")
        return False

    if "proof" not in vc:
        print("[FAIL] VC missing proof")
        return False

    issuer = vc["issuer"]
    if not is_valid_did(issuer):
        print("[FAIL] Invalid issuer DID:", issuer)
        return False

    subject = vc["credentialSubject"].get("subject")
    if not subject or not is_valid_did(subject):
        print("[FAIL] Invalid subject DID:", subject)
        return False

    proof = vc["proof"]
    if "signatureValue" not in proof:
        print("[FAIL] proof missing signatureValue")
        return False

    if audit_only:
        print("[OK] VC audit-only checks passed:", vc.get("id"))
        return True

    # stub verify: recompute signature using same stub secret
    payload = json.dumps(vc["credentialSubject"], sort_keys=True)
    expected = sign_stub("issuer_private_key_stub", payload)

    if expected != proof["signatureValue"]:
        print("[FAIL] Signature mismatch.")
        return False

    print("[OK] VC verified:", vc.get("id"))
    return True


def main():
    parser = argparse.ArgumentParser(description="AIC-SSI VC Verify Tool")
    parser.add_argument("--vc", type=str, required=True, help="VC JSON file")
    parser.add_argument("--audit-only", action="store_true", help="Only check structure")

    args = parser.parse_args()

    with open(args.vc, "r", encoding="utf-8") as f:
        vc = json.load(f)

    ok = verify_vc(vc, audit_only=args.audit_only)
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()