#!/usr/bin/env bash
set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TOOLS_DIR="${ROOT_DIR}/scripts/tools"
OUT_DIR="${ROOT_DIR}/data/vcs"

mkdir -p "${OUT_DIR}"

ISSUER_DID="${1:-}"
SUBJECT_DID="${2:-}"
VC_TYPE="${3:-DemoCredential}"

if [ -z "${ISSUER_DID}" ] || [ -z "${SUBJECT_DID}" ]; then
  echo "[ERROR] Usage:"
  echo "  ./scripts/issue_vc.sh <issuer_did> <subject_did> [type]"
  exit 1
fi

echo "[AIC-SSI] Issue VC"
echo "  issuer  = ${ISSUER_DID}"
echo "  subject = ${SUBJECT_DID}"
echo "  type    = ${VC_TYPE}"

python3 "${TOOLS_DIR}/vc_issue.py" \
  --issuer "${ISSUER_DID}" \
  --subject "${SUBJECT_DID}" \
  --type "${VC_TYPE}" \
  --outdir "${OUT_DIR}"

echo "[DONE] VC issued and stored in ${OUT_DIR}"