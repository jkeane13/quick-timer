#!/bin/bash 

echo ==========================================
echo Linting C files: 80 characters by 50 lines
echo ==========================================
searchDir=src
for file in $searchDir/*
do
      echo Checking $file...
      assets/clinter $file
      errors=$(($errors + $?))
done

if [ $errors -gt 0 ]; then
    echo FAILURE! Files need linting.
    exit 1
else
    echo OK!
fi
