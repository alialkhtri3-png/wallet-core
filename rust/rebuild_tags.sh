#!/data/data/com.termux/files/usr/bin/bash

set -e

echo "=== Fetch latest ==="
git fetch origin --tags

echo "=== Delete remote tags V174-V273 ==="
for v in $(seq 174 273); do
  git push origin --delete v${v}.0.0 2>/dev/null || true
done

echo "=== Delete local tags V174-V273 ==="
for v in $(seq 174 273); do
  git tag -d v${v}.0.0 2>/dev/null || true
done

echo "=== Recreate tags ==="

i=99

for v in $(seq 174 273); do
  git tag -a v${v}.0.0 HEAD~$i \
  -m "Sovereign Identity Rust Core V${v} Stable"
  i=$((i-1))
done

echo "=== Push tags ==="
git push origin --tags

echo "=== Create GitHub release V273 ==="

gh release create v273.0.0 \
--title "Sovereign Identity Rust Core V273 Stable" \
--notes "Sovereign Identity Rust Core V273 - Rust FFI Identity Engine milestone"

echo "=== DONE ==="
