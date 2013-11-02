#!/bin/bash

# To be run with `mosh -c ./wrap.sh ...`

export DYLD_FORCE_FLAT_NAMESPACE=
export DYLD_INSERT_LIBRARIES=readhook.dylib
exec `which mosh-client` "$@"
