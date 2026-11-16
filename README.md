# libsystem

The system C library layer (what `/usr/lib/libSystem.B.dylib` is made of): `libsyscall` (system calls and Mach traps, the user side of `darwinator`), `Libc`, `Libm`, `libpthread`, `libplatform`, `libmalloc`, `libclosure`, `libinfo`, `copyfile`, `removefile`.

**Status: planned** — this repository is empty until the work starts.  It is one piece of a cache of our own for pearOS (see `docs/development/CACHE-LIBRARIES.md` in https://github.com/pearOS-bsd/docs).

Source: the open projects at github.com/apple-oss-distributions (APSL 2.0); our changes are marked as such.
