#!/bin/bash
set -ex

gcc -flat_namespace -dynamiclib -o openhook.dylib openhook.c
gcc -flat_namespace -dynamiclib -o readhook.dylib readhook.c
# TO USE:
# export DYLD_FORCE_FLAT_NAMESPACE=
# export DYLD_INSERT_LIBRARIES=openhook.dylib
