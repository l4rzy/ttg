#include "ttg.h"
#include "ui.h"

static void *td_handle;
static pthread_t thr_handle;
static pthread_mutex_t *mtx;

#if DEBUG_ON
static int gettid() {
	return syscall(SYS_gettid);
}
#endif

static void *ttg_start_tdjson(void *data) {
	if (data != NULL) {
		//do some stuff
	}
	td_handle = td_json_client_create();
	if (td_handle == NULL) {
		TTG_DEBUG_INFO("Could not create telegram client!");
		return NULL;
	}
	else {
		TTG_DEBUG("Telegram client: %p\nThread: %d", td_handle, gettid());
	}

	//do some stuff
	return NULL;
}

int ttg_start() {
	TTG_DEBUG("ttg main routine: %d\n", gettid());
	/*
	 * create the ui first, then start the real telegram client
	 * on another thread
	 */
	ui_initialize();
	ui_draw_dialog(0, 3, "l4zry says hi to the world", "yes");

	ttg_info_t data = {
		.exit = false
	};

	/*
	 * main loop
	 */
	while (!data.exit) {
		key_listen(&data);
	}
	TTG_DEBUG_INFO("Received exit event");
	ttg_stop();

	pthread_create(&thr_handle, NULL, ttg_start_tdjson, NULL);
	return -1;
}

int ttg_stop() {
	TTG_DEBUG_INFO("Calling ttg stop");
	td_json_client_destroy(td_handle);
	ui_finalize();
	return 0;
}
