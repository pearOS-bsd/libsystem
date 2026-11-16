# libsystem

The system C library layer (what `/usr/lib/libSystem.B.dylib` is made of): `libsyscall` (system calls and Mach traps, the user side of `darwinator`), `Libc`, `Libm`, `libpthread`, `libplatform`, `libmalloc`, `libclosure`, `libinfo`, `copyfile`, `removefile`.

**Status: planned** — this repository is empty until the work starts.  It is one piece of a cache of our own for pearOS (see `docs/development/CACHE-LIBRARIES.md` in https://github.com/pearOS-bsd/docs).

Source: the open projects at github.com/apple-oss-distributions (APSL 2.0); our changes are marked as such.

## Upstream sources (starting point)
`upstream/` holds unmodified source of other open projects (see [PROVENANCE.md](PROVENANCE.md): origin, commit, licence), taken so that this repository starts from working code instead of from nothing.  Our own work goes beside it, not inside it.
The survey of the projects these come from: https://github.com/pearOS-bsd/docs/blob/main/development/EXISTING-PROJECTS.md
