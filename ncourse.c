#include <ncurses.h>
#include "win_choose.h"

int main(int argc, char *argv[])
{
  WINDOW *my_win;

	int ch;
  system("resize -s 41 150");
	initscr();	/* Start curses mode 		*/
  curs_set(0);
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);
  //attron(COLOR_PAIR(1));
  bkgd(COLOR_PAIR(1));
	cbreak();
  noecho();
  keypad(stdscr, TRUE);		/* I need that nifty F1 	*/

  refresh();
	my_win = win_choose();

  char c;
  while(c = wgetch(my_win)) {

  }

	endwin();			/* End curses mode		  */
	return 0;
}
