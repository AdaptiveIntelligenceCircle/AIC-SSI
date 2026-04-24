#!/usr/bin/env bash
set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
DATA_DIR="${ROOT_DIR}/data/dids"
TOOLS_DIR="${ROOT_DIR}/scripts/tools"

mkdir -p "${DATA_DIR}"

TYPE="${1:-user}"
KEYTYPE="${2:-Ed25519}"
HINT="${3:-demo}"

echo "[AIC-SSI] Generate DID"
echo "  type    = ${TYPE}"
echo "  keyType = ${KEYTYPE}"
echo "  hint    = ${HINT}"

python3 "${TOOLS_DIR}/vc_issue.py" --generate-did \
  --type "${TYPE}" \
  --keyType "${KEYTYPE}" \
  --hint "${HINT}" \
  --outdir "${DATA_DIR}"

echo "[DONE] DID generated and stored in ${DATA_DIR}"