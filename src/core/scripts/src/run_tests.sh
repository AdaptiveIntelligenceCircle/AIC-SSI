#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"

if [[ ! -d "${BUILD_DIR}" ]]; then
    echo "[ERROR] build directory not found. Run ./scripts/src/build.sh first." >&2
    exit 1
fi

ctest --test-dir "${BUILD_DIR}" --output-on-failure
