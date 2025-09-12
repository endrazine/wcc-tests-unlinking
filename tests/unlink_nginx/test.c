/**
* test.c : v0.1 : Wed Sep  3 10:23:43 CEST 2025
* Jonathan Brossard // endrazine@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <errno.h>

extern u_char *lngx_hex_dump(u_char *dst, u_char *src, size_t len);

void __ctype_init (void){}


int main (int argc, char **argv, char **envp)
{
	char *src = "foobar";
	char dst[20];
	unsigned int i = 0;
	
	memset(dst, 0x00, sizeof(dst));
	ngx_hex_dump(dst, src, strlen(src));

	for (i = 0; i < 2*strlen(src); i += 2) {
		printf("%c%c ", dst[i], dst[i+1]);
	}
	printf("\n");

	return 0;
}
