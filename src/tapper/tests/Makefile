asserts.o: asserts.h asserts.c
	@gcc -c -o asserts.o asserts.c -I.

binary_queue_tests: binary_queue_tests.c ../binary_queue.c ../binary_queue.h asserts.o
	@gcc -o binary_queue_tests binary_queue_tests.c ../binary_queue.c asserts.o -I. -I.. -Wincompatible-pointer-types-discards-qualifiers

tests: clean binary_queue_tests
	@./binary_queue_tests

clean:
	@rm -f *.o binary_queue_tests
