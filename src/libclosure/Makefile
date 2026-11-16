# libclosure: the Blocks runtime (Block_copy, Block_release, _Block_object_assign ...), taken from swift-corelibs-libdispatch/src/BlocksRuntime
# (Apache-2.0 with Runtime Library Exception; see ../../PROVENANCE.md and CHANGES).  Builds a static library for the host (FreeBSD VM test) or Mach-O objects.
#   gmake                      libclosure.a (host)         gmake test      run test/blocks_test.c against it (links OUR runtime, not the system's)
# The Mach-O dylib (for a cache of our own) is built on the Mac VM with the Xcode SDK; not here.
CC = clang
CFLAGS ?= -O2 -g -Wall -Wextra -Wno-unused-parameter -fblocks -I. -Iinclude
OBJ = runtime.o data.o
libclosure.a: $(OBJ)
	ar rcs $@ $(OBJ)
%.o: %.c Block_private.h include/Block.h
	$(CC) $(CFLAGS) -c -o $@ $<
test: libclosure.a
	$(CC) $(CFLAGS) -o blocks_test ../../test/blocks_test.c libclosure.a -lpthread && ./blocks_test
clean:
	rm -f *.o *.a blocks_test
.PHONY: test clean
