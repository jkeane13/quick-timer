#!/bin/bash
set -e

# Create release directory structure
mkdir -p timer-linux-x86_64/bin

# Copy binary
cp timer timer-linux-x86_64/bin/

# Create tarball
tar -czf timer-linux-x86_64.tar.gz timer-linux-x86_64/

# Cleanup
rm -rf timer-linux-x86_64/
