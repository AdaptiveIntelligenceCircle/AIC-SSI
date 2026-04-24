#!/usr/bin/env bash 
set -e 

echo "[AIC-SSI] Build Script" 

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}" 

if [-f "${ROOT_DIR}/MakeLists.txt"]; then 
echo "[INFO] Detected CMake project."
CMake .. -DCMAKE_BUILD_TYPE= Release
CMake --build . --config Release
else
    echo "[WARN] No CMakeLists.txt found."
    echo "[INFO] Fallback build not implemented."
    echo "[HINT] Add CMakeLists.txt or compile manually."
    exit 1
fi

echo "[DONE] Build completed."
