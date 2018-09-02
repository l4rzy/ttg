#include <stdio.h>
#include "ttg.h"
#include <getopt.h>
#include <stdarg.h>

static struct option ttg_option[] = {
	{"help", 0, NULL, 'h'},
	{"version", 0, NULL, 'v'},
	{"debug", 0, NULL, 'd'}
};

static int debug = 0;

void print_help() {
	puts("hge");
}

void print_version() {
	puts("0.1");
}

int main(int argc, char *argv[]) {
	int option;
	option = getopt_long(argc, argv, "h:v:d", ttg_option, NULL);
	switch (option) {
		case 'h':
			print_help();
			break;
		case 'v':
			print_version();
			break;
		case 'd':
			debug = 1;
			break;
		default:
			ttg_start();
	}
}
