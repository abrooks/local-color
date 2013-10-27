#!/bin/bash

# To be run with `mosh -c ./wrap.sh ...`

export DYLD_FORCE_FLAT_NAMESPACE=
export DYLD_INSERT_LIBRARIES=openhook.dylib
exec `which mosh-client` "$@"
