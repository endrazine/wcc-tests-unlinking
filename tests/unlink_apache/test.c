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

void __ctype_init (void){}

extern char *ap_get_server_banner();

int main (int argc, char **argv, char **envp)
{

	printf("%s\n", ap_get_server_banner());

	return 0;
}
