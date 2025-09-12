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
extern char *ap_parse_log_level(const char *str, int *val);

int main (int argc, char **argv, char **envp)
{
	int i = 0;
	char *ret = 0;

	printf("%s\n", ap_get_server_banner());

	if (argc < 2) {
		printf("Usage: %s <loglevel>\n", argv[0]);
		exit(EXIT_SUCCESS);
	}

	ret = ap_parse_log_level(argv[1], &i);
	if (!ret) {
		printf("log level: %d\n", i);
	} else {
		printf("%s\n", ret);
	}

	return 0;
}
