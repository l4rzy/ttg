#ifndef _UI_H_
#define _UI_H_

#include "common.h"
#include <ncurses.h>
#include "ttg.h"
#include "key.h"

#define UI_MINIMUM_SIZE_H 24
#define UI_MINIMUM_SIZE_W 80

enum ui_tab {
	UI_TAB_MAIN,
	UI_TAB_CONTACT,
	UI_TAB_ACTION,
	UI_TAB_NOTIFICATION
};

enum ui_mode {
	UI_MODE_NORMAL,
	UI_MODE_EDIT,
	UI_MODE_VISUAL
};

void ui_initialize(void);
void ui_finalize(void);
bool ui_size_ok(void);
void ui_draw_main(const ttg_info_t *data);
void ui_draw_contact(const ttg_info_t *data);
void ui_draw_action(const ttg_info_t *data);
void ui_draw_notification(const ttg_info_t *data);
void ui_redraw(const ttg_info_t *data);
void ui_draw_dialog(int x_gap, int y_gap, const char *title, const char *message);

#endif
