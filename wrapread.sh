#!/bin/bash

# To be run with `./wrap.sh ssh ...`
# ...or other command.

export DYLD_FORCE_FLAT_NAMESPACE=
export DYLD_INSERT_LIBRARIES=readhook.dylib
exec "$@"
