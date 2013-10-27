#!/bin/bash
set -ex

gcc -flat_namespace -dynamiclib -o openhook.dylib openhook.c
# TO USE:
# export DYLD_FORCE_FLAT_NAMESPACE=
# export DYLD_INSERT_LIBRARIES=openhook.dylib
