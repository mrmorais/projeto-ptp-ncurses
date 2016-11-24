#ifndef _WINDOW_H_
#define _WINDOW_H_
#define CS_HEIGHT 33
#define CS_WIDTH 110
#define CS_STARTX 5
#define CS_STARTY 4


WINDOW *create_newwin();
WINDOW *create_cnewwin(int height, int width, int startx, int starty);
void setFooter(WINDOW* win, char* text);
void destroy_win(WINDOW *local_win);

#endif
