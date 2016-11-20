#include <ncurses.h>

WINDOW *create_newwin() {
  int startx, starty, width, height;
  height = LINES - 4;
	width = COLS - 4;
	starty = (LINES - height) / 2;	/* Calculating for a center placement */
	startx = (COLS - width) / 2;	/* of the window		*/

  WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);
  wbkgd(local_win, COLOR_PAIR(2));
  wmove(local_win, 1,2);

  wrefresh(local_win);
	return local_win;
}

WINDOW *create_cnewwin(int height, int width, int startx, int starty) {
  WINDOW *local_win;
  local_win = newwin(height, width, startx, starty);
  box(local_win, 0 , 0);
  wbkgd(local_win, COLOR_PAIR(2));
  wmove(local_win, 1,2);

  wrefresh(local_win);
  return local_win;
}

void setFooter(WINDOW* win, char* text) {
  wmove(win, 36, 2);
  wprintw(win, text);
}

void destroy_win(WINDOW *local_win) {
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
