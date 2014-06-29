/*
 * @file parse-akconfig
 * 
 * @author Akagi201
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "iniparser.h"

int parse_ini_file(char * ini_name);

int main(int argc, char * argv[]) {
	int status;

	status = parse_ini_file("akconfig.ini");

	return status;
}

int parse_ini_file(char *ini_name) {
	dictionary *ini = NULL;

	int port = 0;

	char *ip = NULL;

	ini = iniparser_load(ini_name);
	if (NULL == ini) {
		fprintf(stderr, "cannot parse file: %s\n", ini_name);
		return -1;
	}
	//iniparser_dump(ini, stderr);

	port = iniparser_getint(ini, "server:port", -1);
	printf("server: [%d]\n", port);

	ip = iniparser_getstring(ini, "server:ip", NULL);
	printf("ip: [%s]\n", ip ? ip : "UNDEF");

	iniparser_freedict(ini);
	return 0;
}

