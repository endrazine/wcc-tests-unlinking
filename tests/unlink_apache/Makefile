CC := gcc
CFLAGS := -W -Wall -pie -fPIE -fPIC -g3 -ggdb
LDFLAGS := $(shell ldd /usr/sbin/apache2|grep .so|awk '{print $$3}'|grep .|xargs)

LDFLAGSSTATIC := $(shell ldd /usr/sbin/apache2|grep .so|awk '{print $$3}'|grep .|xargs|sed s#"\.so\.[^\ ]*"#".a"#gi)


all::
	wcc /usr/sbin/apache2 -o ./apache2.o -c -v
	ar rcs apache2.a apache2.o
	$(CC) $(CFLAGS) test.c -o test.o -c
	$(CC) $(CFLAGS) apache2.o test.o -o test $(LDFLAGS)
	$(CC) $(CFLAGS) test.o -o test2 apache2.a $(LDFLAGS)

	$(CC) $(CFLAGS) -Wl,--allow-multiple-definition test.c apache2.o -o test3 -static $(LDFLAGSSTATIC)


test::
	./test
	./test2
	./test3

simple::
	LD_PRELOAD=./libsimple.so ./test2 emerg

hard::
	LD_PRELOAD=./libsimple.so ./test2 info

clean::
	rm -f test apache2.o test.o test test2 apache2.a test3

