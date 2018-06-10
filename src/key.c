#include "key.h"

/*
 * global variables from ui
 */
extern int ui_status_tab;
extern int ui_status_mode;

/*
 * static functions
 */
static void key_handle_main(ttg_info_t *data, wint_t key);
static void key_handle_contact(ttg_info_t *data, wint_t key);
static void key_handle_action(ttg_info_t *data, wint_t key);

void key_listen(ttg_info_t *data) {
	int errn;
	wint_t c = 0;

	//get the key
	errn = get_wch(&c);
	if (errn == ERR) {
		TTG_FATAL("Failed to get keyboard event");
	}
	TTG_DEBUG("Got key event: %d\n", c);

	if (c == KEY_RESIZE) {
		TTG_DEBUG_INFO("Resizing terminal ...");
		if (!ui_size_ok()) {
			TTG_FATAL("Terminal is too small :(");
		}
		ui_redraw(data);
	}

	switch (ui_status_tab) {
		case UI_TAB_MAIN:
			key_handle_main(data, c);
			break;
		case UI_TAB_CONTACT:
			key_handle_contact(data, c);
			break;
		case UI_TAB_ACTION:
			key_handle_action(data, c);
			break;
		default:
			break;
	}
}

static void key_handle_main(ttg_info_t *data, wint_t key) {
	switch (key) {
		case 'q':
			data->exit = true;
			break;
		case 'i':
			cbreak();

		default:
			break;
	}
}

static void key_handle_contact(ttg_info_t *data, wint_t key) {
	switch (key) {
		case 'a':
			//add new contact
			break;
		default:
			break;
	}
}

static void key_handle_action(ttg_info_t *data, wint_t key) {
	switch (key) {
		case 'n':
		default:
			break;
	}
}
