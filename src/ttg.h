#ifndef _TTG_H_
#define _TTG_H_

#include "common.h"
#include <td/telegram/td_json_client.h>
#include <sys/types.h>
#include <sys/syscall.h>

struct _message_t {
	byte *message;
};
typedef struct _message ttg_message_t;

struct _ttg_info {
	bool exit;
};
typedef struct _ttg_info ttg_info_t;

int ttg_start();
int ttg_stop();

#endif
