#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

typedef unsigned char byte;

#ifdef DEBUG_ON
#define TTG_DEBUG(fmt, ...) \
	do {\
		FILE *fp; \
		fp = fopen("debug.log", "a+"); \
		if (fp == NULL) { \
			fp = stdout; \
		} \
		fprintf(fp, "[%s:%d:%s()] "fmt, __FILE__, __LINE__, \
				__func__, __VA_ARGS__); \
		fclose(fp); \
	} while (0);

#define TTG_DEBUG_INFO(info) \
	TTG_DEBUG("%s\n", info)
#else
#define TTG_DEBUG(fmt, ...) \
	(void)0;

#define TTG_DEBUG_INFO(fmt, ...) \
	(void)0;
#endif //DEBUG_ON

#define TTG_FATAL(msg) \
	do {\
		fprintf(stdout, "[%s:%d:%s()] "msg, __FILE__, __LINE__, \
			__func__); \
		ui_finalize(); \
		exit(-1); \
	} while (0);

#endif
