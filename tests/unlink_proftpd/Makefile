CC := gcc
CFLAGS := -W -Wall -pie -fPIE -fPIC -g3 -ggdb
LDFLAGS := $(shell ldd /usr/sbin/proftpd|grep .so|awk '{print $$3}'|grep .|xargs)

LDFLAGSSTATIC := /lib/x86_64-linux-gnu/libcrypt.a /lib/x86_64-linux-gnu/libhiredis.a ./libmemcachedutil.o ./libmemcached.o /lib/x86_64-linux-gnu/libhiredis_ssl.a /lib/x86_64-linux-gnu/libacl.a /lib/x86_64-linux-gnu/libpcre2-posix.a /lib/x86_64-linux-gnu/libpcre2-8.a /lib/x86_64-linux-gnu/libcrypto.a /lib/x86_64-linux-gnu/libcap.a /lib/x86_64-linux-gnu/libpam.a /lib/x86_64-linux-gnu/libc.a ./libstdc++.o ./libhashkit.o /lib/x86_64-linux-gnu/libsasl2.a ./libgcc_s.o /lib/x86_64-linux-gnu/libssl.a /lib/x86_64-linux-gnu/libaudit.a /lib/x86_64-linux-gnu/libm.a /lib/x86_64-linux-gnu/libcap-ng.a


all::
	wcc /usr/sbin/proftpd -o ./proftpd.o -c -v
	ar rcs proftpd.a proftpd.o
	$(CC) $(CFLAGS) test.c -o test.o -c
	$(CC) $(CFLAGS) proftpd.o test.o -o test $(LDFLAGS)
	$(CC) $(CFLAGS) test.o -o test2 proftpd.a $(LDFLAGS)

#	wcc /usr/lib/x86_64-linux-gnu/libhashkit.so -o libhashkit.o -c
#	wcc /lib/x86_64-linux-gnu/libmemcachedutil.so -o libmemcachedutil.o -c
#	wcc /lib/x86_64-linux-gnu/libmemcached.so -o libmemcached.o -c
#	wcc /lib/x86_64-linux-gnu/libgcc_s.so.1 -o libgcc_s.o -c
#	wcc /lib/x86_64-linux-gnu/libstdc++.so.6 -o libstdc++.o -c

#	$(CC) $(CFLAGS) -Wl,--allow-multiple-definition test.c proftpd.o -o test3 -static $(LDFLAGSSTATIC)

test::
	./test
	./test2

clean::
	rm -f test proftpd.o test.o test test2 proftpd.a test3

