#!/usr/bin/env bash
set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DATA_DIR="${ROOT_DIR}/data"

echo "[AIC-SSI] Audit Check"

if [ ! -d "${DATA_DIR}" ]; then
  echo "[WARN] data/ directory not found. Nothing to audit."
  exit 0
fi

echo "[INFO] Scanning DID Documents..."
if [ -d "${DATA_DIR}/dids" ]; then
  for f in "${DATA_DIR}/dids/"*.json; do
    if [ -f "$f" ]; then
      python3 "${ROOT_DIR}/scripts/tools/did_resolve.py" --validate "$f"
    fi
  done
fi

echo "[INFO] Scanning Verifiable Credentials..."
if [ -d "${DATA_DIR}/vcs" ]; then
  for f in "${DATA_DIR}/vcs/"*.json; do
    if [ -f "$f" ]; then
      python3 "${ROOT_DIR}/scripts/tools/vc_verify.py" --vc "$f" --audit-only
    fi
  done
fi

echo "[DONE] Audit check completed."