#ifndef _WINDOW_H_
#define _WINDOW_H_

WINDOW *create_newwin();
WINDOW *create_cnewwin();
void setFooter(WINDOW* win, char* text);
void destroy_win(WINDOW *local_win);

#endif
