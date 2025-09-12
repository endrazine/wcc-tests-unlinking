CC := gcc
CFLAGS := -W -Wall -pie -fPIE -fPIC -g3 -ggdb
LDFLAGS := $(shell ldd /usr/sbin/apache2|grep .so|awk '{print $$3}'|grep .|xargs)

all::
	wcc /usr/sbin/apache2 -o ./apache2.o -c -v
	ar rcs apache2.a apache2.o
	$(CC) $(CFLAGS) test.c -o test.o -c
	$(CC) $(CFLAGS) apache2.o test.o -o test $(LDFLAGS)
	$(CC) $(CFLAGS) test.o -o test2 apache2.a $(LDFLAGS)

test::
	./test foobar
	./test emerg
	./test info
	./test alert
	./test2 foobar
	./test2 emerg
	./test2 info
	./test2 alert


clean::
	rm -f test apache2.o test.o test test2 apache2.a apache2

