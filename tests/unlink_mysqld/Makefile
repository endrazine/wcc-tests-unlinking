CC := gcc
CFLAGS := -W -Wall -pie -fPIE -fPIC -g3 -ggdb
LDFLAGS := $(shell ldd /usr/sbin/mysqld|grep .so|awk '{print $$3}'|grep .|xargs)

all::
	cp /usr/sbin/mysqld .
	wld -n -l mysqld
	wcc mysqld -o ./mysqld.o -c -v -n
	ar rcs mysqld.a mysqld.o
	$(CC) $(CFLAGS) test.c -o test.o -c
	$(CC) $(CFLAGS) mysqld.o test.o -o test $(LDFLAGS)
	$(CC) $(CFLAGS) test.o -o test2 mysqld.a $(LDFLAGS)

test::
	./test
	./test2

clean::
	rm -f test mysqld.o test.o test test2 mysqld.a mysqld

