#include "ui.h"

/*
 * global variables
 */
int ui_status_tab = UI_TAB_MAIN;
int ui_status_mode = UI_MODE_NORMAL;

/*
 * static functions
 */
static void ui_draw_chat(const ttg_info_t *data);

static void ui_get_size(int *h, int *w) {
	getmaxyx(stdscr, *h, *w);
}

bool ui_size_ok(void) {
	int h, w;

	ui_get_size(&h, &w);
	if (h < UI_MINIMUM_SIZE_H ||
			w < UI_MINIMUM_SIZE_W) {
		return false;
	}
	return true;
}
/*
 * initializes the ui
 */


void ui_initialize(void) {
	TTG_DEBUG_INFO("Preparing ui");
	/* to save the return value */
	int ret;
#define CHECK_RET(unexpected) \
	if (ret == unexpected) {\
		goto err; \
	}
/* end define */

	if (initscr() == NULL) {
		goto err;
	}
	
	/*
	 * check screen size
	 */
	if (!ui_size_ok()) {
		TTG_FATAL("Terminal is too small, try to enlarge it and try again!");
	}
	
	/* hide the cursor */
	ret = curs_set(0);
	CHECK_RET(ERR);
	
	/* use the keyboard */
	ret = keypad(stdscr, true);
	CHECK_RET(ERR);

	/* disable echoing on screen */
	ret = noecho();
	CHECK_RET(ERR);

	/* prevent enter from creating a new line */
	ret = nonl();
	CHECK_RET(ERR);

	(void)clear();
#undef CHECK_RET
	return;
err:
	ui_finalize();
	TTG_FATAL("Could not initialize ncurses\n");
}

void ui_redraw(const ttg_info_t *data) {
	refresh();
}

void ui_finalize(void) {
	TTG_DEBUG_INFO("Exitting ui");
	(void)endwin();
}

void ui_draw_dialog(int size, const char *title, const char  *message) {
	//get stdscr size
	int h, w;
	
	ui_get_size(&h, &w);
	int dialog_h;
	int dialog_w;
	switch (size) {
		case UI_DIALOG_LARGE:
			dialog_h = h - 3;
			dialog_w = w - 3;
			break;
		case UI_DIALOG_MEDIUM:
		default:
			dialog_h = h - 5;
			dialog_w = w - 5;
			break;
		case UI_DIALOG_SMALL:
			dialog_h = h - 7;
			dialog_w = w - 7;
			break;
	}
	
	TTG_DEBUG("Creating a dialog with width=%d and height=%d\n",
			dialog_w, dialog_h);
	//boder of the dialog
	for (int dw =0 ; dw < dialog_w; ++dw) {
		//left
		mvprintw(dialog_h, dw, "x");
		//right
	}

	for (int h = 0; h < dialog_h; ++h) {
		//top
		
		//bottom
	}
}
