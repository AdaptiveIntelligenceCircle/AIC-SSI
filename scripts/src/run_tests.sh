#!/usr/bin/env bash
set -e

echo "[AIC-SSI] Running Tests"

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"

if [ ! -d "${BUILD_DIR}" ]; then
    echo "[ERROR] build/ directory not found."
    echo "[HINT] Run ./scripts/build.sh first."
    exit 1
fi

cd "${BUILD_DIR}"

if [ -f "./aic_ssi_tests" ]; then
    echo "[INFO] Running unit test binary..."
    ./aic_ssi_tests
    echo "[DONE] Tests finished."
    exit 0
fi

if [ -f "./tests/aic_ssi_tests" ]; then
    echo "[INFO] Running unit test binary..."
    ./tests/aic_ssi_tests
    echo "[DONE] Tests finished."
    exit 0
fi

echo "[WARN] No test binary found."
echo "[HINT] Ensure you build a test target named aic_ssi_tests."
exit 1