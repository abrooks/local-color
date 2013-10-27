# Sit back and enjoy the local color

local-color is a interposer library (via `LD_PRELOAD` on Linux,
`DYLD_INSERT_LIBRARIES` on OS X) which allows local color
customization of a remote session (via mosh or ssh).

## Rationale

  "Why?? Why would you do this?"

Many terminal programs allow you to set the fixed ANSI 16 colors, or
even the 256 color pallet. Some terminals allow you programmatically
change your color scheme. Remote terminal sessions (particularly
pairing with collaborative team members) can make color setting and
translation very complex for all parties. There may be problems
between the conflicting interests of each developer's local terminal
defaults and remote editor syntax hilighting.

local-color aims to provide a color abstraction interface that is
cross-platform, context sensitive, coordinated and dynamic. By
monitoring hints such as terminal title sequences, colors can be
properly set for different contexts.

Furthermore, competing color blindness, different local lighting
environments can make it undesirable or even impossible to share a
single, unified color scheme (even if that were easily attainable).

## To Do

Pretty much everything.

* LD_PRELOAD version for Linux
* IPC for externally registering & monitoring color usage
* proper cross platform build tools
* state machine for managing full color state
* Support more than just mosh
