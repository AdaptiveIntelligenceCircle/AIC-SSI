#!/usr/bin/env python3 

import json 
import argparse 
import os 
import time 
import hashlib

def now_iso8601():
    return time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime())

def fake_hash(s: str) -> str: 
    return hashlib.sha256(s.encode("Utf-8")).hexdigest()

def make_filename(did : str) -> str: 
    return did.replace(":", "_") + ".json"

def generate_did_doc(did_type : str, key_type: str, hint: str):
    ts = str(int(time.time()*1000))
    did = f"did::aic:{did_type}:{ts}"

    doc = {
        "id": did, 
        "created": now_iso8601, 
        "updated": now_iso8601,
        "verificationMethods":[
            { 
                "id": f"{did}#key-1", 
                "type": key_type, 
                "controller": did, 
                "publicKey": fake_hash("pub::" + did), 
            }
        ], 
        "services":[]

    }
    if hint:
        doc["services"].append({
            "id": f"{did}#service-1",
            "type": "AICHint",
            "endpoint": hint
        })
    return doc 

def sign_stub(private_key: str, payload: str) -> str: 
    #placeholder signature logic.. 
    return fake_hash("sig::" + private_key + "::" + payload)

def issue_vc(issuer: str, subject: str, vc_type: str):
    vc_id = "vc:" + fake_hash(issuer + subject + vc_type + now_iso8601())[:16]

    claims = {
        "subject": subject,
        "issuedAt": now_iso8601(),
        "type": vc_type,
        "meta": {
            "aic_policy": "ethical-identity-policy",
            "trust": "baseline"
        }
    }

    vc = {
        "@context": ["https://www.w3.org/2018/credentials/v1"],
        "id": vc_id,
        "type": ["VerifiableCredential", vc_type],
        "issuer": issuer,
        "credentialSubject": claims,
        "issuanceDate": now_iso8601(),
        "proof": {
            "type": "AICStubSignature2026",
            "created": now_iso8601(),
            "proofPurpose": "assertionMethod",
            "verificationMethod": issuer + "#key-1",
            "signatureValue": sign_stub("issuer_private_key_stub", json.dumps(claims, sort_keys=True))
        }
    }

    return vc

def main(): 
    parser = argparse.ArgumentParser(description= "AIC-SSI VC Issuer Tool")
    
    parser.add_argument("--generate-did", action="store_true", help="Generate DID Document")
    parser.add_argument("--type", type=str, default="user", help="DID type (user/node/org)")
    parser.add_argument("--keyType", type=str, default="Ed25519", help="Key algorithm")
    parser.add_argument("--hint", type=str, default="", help="Service hint")
    parser.add_argument("--outdir", type=str, default="data", help="Output directory")

    parser.add_argument("--issuer", type=str, help="Issuer DID")
    parser.add_argument("--subject", type=str, help="Subject DID")
    parser.add_argument("--type-vc", type=str, dest="vc_type", help="VC Type")
    parser.add_argument("--type", type=str, help="(deprecated alias for vc type)")

    args = parser.parse_args()

    os.makedirs(args.outdir, exist_ok=True)

    # DID generation mode.. 
    if args.generate_did: 
        doc = generate_did_doc(args.type, args.keyType, args.hint)
        did = doc["id"]
        filename = make_filename(did)
        outpath  = os.path.join(args.outdir, filename)

        with open(outpath, "w", encoding="utf-8") as f: 
            json.dump(doc, f, indent=4)
        
        print("[OK] DID Created:", did)
        print("[OUT]", outpath)
        return 
    
    #VC issue mode.. 
    if args.issuer and args.subject: 
        vc_type = args.vc_type if args.vc_type else "DemoCredential"
        vc = issue_vc(args.issuer, args.subject, vc_type)

        filename = vc["id"].replace(":", "_") + ".json"
        outpath = os.path.join(args.outdir, filename)

        with open(outpath, "W", encoding="utf-8") as f:
            json.dump(vc, f, indent = 4)
        
        print("OK - VC Issued:", vc["id"])
        print("OUT", outpath)
        return 
    
    print("ERROR- Invalid usage.")
    print("Use -- generate-did OR --issuer --subject")
    exit(1)

if __name__ == "__main__":
    main()