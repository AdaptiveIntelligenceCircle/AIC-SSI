#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"

if [[ ! -f "${ROOT_DIR}/CMakeLists.txt" ]]; then
    echo "[ERROR] CMakeLists.txt not found at repository root: ${ROOT_DIR}" >&2
    exit 1
fi

cmake -S "${ROOT_DIR}" -B "${BUILD_DIR}" -DCMAKE_BUILD_TYPE=Release
cmake --build "${BUILD_DIR}" --config Release --parallel
