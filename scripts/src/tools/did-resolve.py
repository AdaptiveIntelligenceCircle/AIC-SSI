#! /usr/bin/env python3 

import json 
import argparse
import os 
import sys 

def load_json(path: str):
    with open(path, "r", encoding="utf-8") as f:
        return json.load(f)

def is_valid_did(did: str) -> bool: 
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

def validate_did_document(doc:dict) -> bool: 
    if "id" not in doc: 
        print("[FAIL] DID Document missing 'id'")
        return False 
    
    did = doc["id"]
    if not isinstance(did, str) or not is_valid_did(did):
        print("FAIL Invalid DID:", did)
        return False 
    if "verificationMethods" not in doc or not isinstance(did):
        print("Fail- Missing verificationMethods array")
        return False 
    if len(doc["verificationMethods"]) == 0:
        print("[Fail] - verificationMethods is empty")
        return False 
    
    ok_controller = False 
    for vm in doc["verificationMethods"]:
        if not isinstance(vm, dict):
            continue 
        if vm.get("controller") == did: 
            ok_controller = True 
        
        if not ok_controller:
            print("Fail- No verification method controlled")
            return False 
        
        return True 
    
def resolve_did(did: str, did_str: str):
    if not is_valid_did(did):
        print("Error-Invalid DID Format")
        return None 
    
    # Simplistic storage mapping:
    # file name = did replaced ":" -> "_"
    filename = did.replace(":", "_") + ".json"
    path = os.path.join(did_str, filename)

    if not os.path.exists(path):
        return None 
    return load_json(path)

def main():
    parser = argparse.ArgumentParser(description= "AIC-SSI DID Resolve Tool")
    parser.add_argument("--did", type=str, help="Resolve DID from local storage")
    parser.add_argument("--dir", type=str, default="data/dids", help="DID directory")
    parser.add_argument("--validate", type=str, help="Validate DID document JSON file")

    args = parser.parse_args()

    if args.validate:
        doc = load_json(args.validate)
        ok = validate_did_document(doc)
        if ok:
            print("OK - DID Document valid:", doc.get[""])
            sys.exit(0)
        else: 
            sys.exit(1)
    
    if args.did:
        doc = resolve_did(args.did, args.dir)
        if doc is None:
            print("FAIL - DID not found:", args.did)
            sys.exit(1)
        
        ok = validate_did_document(doc)
        if not ok: 
            print("FAIL-DID Document invalid:", args.did)
            sys.exit(0)

        print("[Error] - No action provided. Use --did or --valid")
        sys.exit(1)

if __name__ == "__main__":
    main()
    