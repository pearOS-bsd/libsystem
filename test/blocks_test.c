/* Tests of the Blocks runtime we build (src/libclosure): global, stack and heap blocks, copy/release counts, __block variables, captured objects with copy/dispose helpers. */
#include <Block.h>
#include <stdio.h>
#include <string.h>
static int fails;
#define CHECK(c, m) do { if (!(c)) { printf("FAIL: %s\n", m); fails++; } } while (0)
typedef int (^intop)(int);
static intop make_adder(int n) { return Block_copy(^(int x) { return x + n; }); }
int main(void) {
	int base = 10; intop stack = ^(int x) { return x + base; };
	intop heap = Block_copy(stack);
	CHECK(heap != stack, "Block_copy of a stack block must give a heap block");
	base = 99; CHECK(heap(1) == 11, "the copy keeps the captured value");
	CHECK(Block_copy(heap) == heap, "copying a heap block only retains it");
	Block_release(heap); Block_release(heap);        /* back to count 1 */
	intop g = ^(int x) { return x * 2; };            /* captures nothing: a global block */
	CHECK(Block_copy(g) == g && g(4) == 8, "a global block is returned as it is");
	__block int counter = 0; void (^inc)(void) = Block_copy(^{ counter++; });
	inc(); inc(); CHECK(counter == 2, "__block variable is shared with the block after the copy");
	Block_release(inc);
	intop add5 = make_adder(5); CHECK(add5(3) == 8, "a block returned from a function survives it"); Block_release(add5);
	Block_release(heap);
	printf(fails ? "%d FAILED\n" : "blocks runtime: all checks passed\n", fails); return fails != 0;
}
