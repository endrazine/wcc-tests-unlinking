CC := gcc
CFLAGS := -W -Wall -pie -fPIE -fPIC -g3 -ggdb
LDFLAGS := $(shell ldd /usr/sbin/nginx|grep .so|awk '{print $$3}'|grep .|xargs)

all::
	wcc /usr/sbin/nginx -o ./nginx.o -c -v
	ar rcs nginx.a nginx.o
	$(CC) $(CFLAGS) test.c -o test.o -c
	$(CC) $(CFLAGS) nginx.o test.o -o test $(LDFLAGS)
	$(CC) $(CFLAGS) test.o -o test2 nginx.a $(LDFLAGS)

test::
	./test
	./test2

clean::
	rm -f test nginx.o test.o test test2 test3 nginx.a

