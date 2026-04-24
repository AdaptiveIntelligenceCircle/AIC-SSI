#!/usr/bin/env bash
set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
TOOLS_DIR="${ROOT_DIR}/scripts/tools"

VC_FILE="${1:-}"

if [ -z "${VC_FILE}" ]; then
  echo "[ERROR] Usage:"
  echo "  ./scripts/verify_vc.sh <vc_json_file>"
  exit 1
fi

if [ ! -f "${VC_FILE}" ]; then
  echo "[ERROR] VC file not found: ${VC_FILE}"
  exit 1
fi

echo "[AIC-SSI] Verify VC"
python3 "${TOOLS_DIR}/vc_verify.py" --vc "${VC_FILE}"