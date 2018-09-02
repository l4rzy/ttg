#include "ui.h"

/*
 * global variables
 */
int g_ui_status_tab = UI_TAB_MAIN;
int g_ui_status_mode = UI_MODE_NORMAL;

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

void ui_draw_dialog(int x_gap, int y_gap, const char *title, const char  *message) {
	//get stdscr size
	int h, w;
	
	ui_get_size(&h, &w);
	int dialog_y = h - y_gap - 1;
	int dialog_x = w - x_gap - 1;
	
	TTG_DEBUG("Creating a dialog with width=%d and height=%d\n",
			dialog_x, dialog_y);
	//boder of the dialog
	for (int x = x_gap; x < dialog_x; ++x) {
		//left
		//mvprintw(dialog_h, dw, "%c", ACS_HLINE);
		mvaddch(dialog_y, x, ACS_HLINE);
		mvaddch(y_gap, x, ACS_HLINE);
		//right
	}

	for (int y = y_gap; y < dialog_y; ++y) {
		mvaddch(y, x_gap, ACS_VLINE);
		mvaddch(y, dialog_x, ACS_VLINE);
	}
	mvaddch(dialog_y, x_gap, ACS_LLCORNER);
	mvaddch(dialog_y, dialog_x, ACS_LRCORNER);

	mvaddch(y_gap, dialog_x, ACS_URCORNER);
	mvaddch(y_gap, x_gap, ACS_ULCORNER);
}
