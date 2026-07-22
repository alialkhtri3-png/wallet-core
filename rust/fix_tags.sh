#!/data/data/com.termux/files/usr/bin/bash

set -e

REPO="origin"

echo "=== Cleaning local tags ==="

git tag -l "v*.0.0" | xargs -r git tag -d


echo "=== Removing remote tags V174-V273 ==="

for v in $(seq 174 273); do
    git push $REPO --delete v${v}.0.0 2>/dev/null || true
done


echo "=== Recreating tags ==="

for v in $(seq 174 273); do
    OFFSET=$((273-v))
    git tag -a v${v}.0.0 HEAD~${OFFSET} \
    -m "Sovereign Identity Rust Core V${v} Stable"
done


echo "=== Pushing tags ==="

git push $REPO --tags


echo "=== Checking V273 ==="

git show v273.0.0 --stat


echo "=== Updating GitHub Release ==="

gh release edit v273.0.0 \
--title "Sovereign Identity Rust Core V273 Stable" \
--notes "Sovereign Identity Rust Core V273 - Rust FFI Identity Engine milestone" \
|| echo "Release update skipped"


echo "=== DONE ==="

git tag --list "v27*"
