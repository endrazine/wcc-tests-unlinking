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

extern char *print_version();

int main (int argc, char **argv, char **envp)
{
	print_version();
	return 0;
}
