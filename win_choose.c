#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include "window.h"
#include "win_funcionario.h"

char *choices[] = {
  "Funcionário",
  "Consumidor",
  "Sobre",
  "Sair"
};
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu, int highlight);

WINDOW *win_choose() {
  WINDOW *lw = create_newwin();
  int x = 6; int y = 36;
  wmove(lw, x, y);
  wprintw(lw, "______           _                        _         ________  ________ "); wmove(lw, x+1, y);
  wprintw(lw, "| ___ \\         | |                      | |       |_   _|  \\/  |  _  \\"); wmove(lw, x+2, y);
  wprintw(lw, "| |_/ /_   _  __| | ___  __ _  __ _    __| | ___     | | | .  . | | | |"); wmove(lw, x+3, y);
  wprintw(lw, "| ___ \\ | | |/ _` |/ _ \\/ _` |/ _` |  / _` |/ _ \\    | | | |\\/| | | | |"); wmove(lw, x+4, y);
  wprintw(lw, "| |_/ / |_| | (_| |  __/ (_| | (_| | | (_| | (_) |  _| |_| |  | | |/ / "); wmove(lw, x+5, y);
  wprintw(lw, "\\____/ \\__,_|\\__,_|\\___|\\__, |\\__,_|  \\__,_|\\___/   \\___/\\_|  |_/___/  "); wmove(lw, x+6, y);
  wprintw(lw, "                         __/ |                                         "); wmove(lw, x+7, y);
  wprintw(lw, "                        |___/                                          "); move(0, 0);

  // wmove(lw, 1, 50);
  // wprintw(lw,"hi");

  WINDOW *menu = create_cnewwin(10, 40, 20, 50);
  keypad(menu, TRUE);
  wprintw(menu, "Bem vindo ao Budega do IMD.");
  wmove(menu, 2, 2);
  wprintw(menu, "Selecione uma opção:");

  setFooter(lw, " Use as setas para subir e descer. ENTER para selecionar uma opção ");

  int highlight = 1;
  int choice = 0;
  int c = 0;

  // setFooter("");
  wrefresh(lw);
  print_menu(menu, highlight);
  /*
  * Eu do futuro: Espero que você entenda o que está acontecendo aqui.
  * Por que eu não entendo não.
  */
  while(1) {
    c = wgetch(menu);

    switch (c) {
      case KEY_UP:
        if(highlight == 1)
          highlight = n_choices;
        else
          --highlight;
      break;
      case KEY_DOWN:
        if(highlight == n_choices)
          highlight = 1;
        else
          ++highlight;
      break;
      case 10:
        choice = highlight;
        break;
    }
    print_menu(menu, highlight);
    if(choice != 0) {
      break;
    }
  }

  WINDOW *win_func;
  switch (choice) {
    case 1:
      destroy_win(menu);
      destroy_win(lw);
      win_func = win_funcionario();
    break;
    case 2:
    break;
    case 3:
    break;
    case 4:
      endwin();
      exit(0);
    break;
  }

	refresh();

  return lw;
}

void print_menu(WINDOW* menu, int highlight) {
  int x=4, y=2, i;
  for(i=0; i < n_choices; ++i) {
    if(highlight == i + 1) {
      wattron(menu, A_REVERSE);
      mvwprintw(menu, x, y, "%s", choices[i]);
      wattroff(menu, A_REVERSE);
    } else {
      mvwprintw(menu, x, y, "%s", choices[i]);
    }
    ++x;
  }
  // wmove(menu, 0, 0);
  wrefresh(menu);
}
