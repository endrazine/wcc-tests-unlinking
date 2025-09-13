CC := gcc
WCC = wcc
CFLAGS := -W -Wall -Wextra

all::
	$(CC) $(CFLAGS) small.c -o small
	$(WCC) small -o small_wcc.o -c -v -d -k
	$(CC) $(CFLAGS) small_wcc.o -o small-relinked
	$(CC) $(CFLAGS) small_wcc.o -o small-relinked-static -static

clean::
	rm -f small small-relinked small-relinked-static small_wcc.o

test::
	./small-relinked ||:
	./small-relinked-static ||:
