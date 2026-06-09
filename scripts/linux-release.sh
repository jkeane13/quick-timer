#!/bin/bash
set -e

# Create release directory structure
mkdir -p timer-linux-x86_64/bin
mkdir -p timer-linux-x86_64/assets
mkdir -p timer-linux-x86_64/config

# Copy binary and assets
cp timer timer-linux-x86_64/bin/
cp assets/*.mp3 timer-linux-x86_64/assets/
cp config/*.cfg timer-linux-x86_64/config/

# Create tarball
tar -czf timer-linux-x86_64.tar.gz timer-linux-x86_64/

# Cleanup
rm -rf timer-linux-x86_64/
