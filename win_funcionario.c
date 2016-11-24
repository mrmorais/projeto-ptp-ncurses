#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include <string.h>
#include "window.h"
#include "win_f_products.h"
#include "win_funcionario.h"

char *choices_f[] = {
  "Buscar produto",
  "Cadastrar novo produto",
  "Reposição de estoque",
  "Voltar"
};
int n_choices_f = sizeof(choices_f) / sizeof(char *);

WINDOW *win_funcionario() {
  WINDOW *lw = create_newwin(); //Local Screen
  WINDOW *cs; //Central Screen

  wmove(lw, 1, 2);
  wprintw(lw, "BUDEGA DO IMD | AREA PARA FUNCIONARIOS");
  wmove(lw, 2, 2);
  whline(lw, '-', 143);

  setFooter(lw, " Use as setas para subir e descer. ENTER para selecionar uma opção ");

  cs = win_f_products();

  WINDOW *menu = create_cnewwin(10, 32, 5, 115); //Menu
  //Escreve PRODUTOS no topo
  wmove(menu, 1, 2);
  wattron(menu, A_BOLD);
  wprintw(menu, "MENU");
  wattroff(menu, A_BOLD);

  int highlight = 1;
  int choice = 0;
  int c = 0;

  wrefresh(lw);
  print_menu_f(menu, highlight);

  while(1) {
    c = wgetch(menu);

    switch (c) {
      case 65:
        if(highlight == 1)
          highlight = n_choices_f;
        else
          --highlight;
      break;
      case 66:
        if(highlight == n_choices_f)
          highlight = 1;
        else
          ++highlight;
      break;
      case 10:
        choice = highlight;
        break;
    }
    print_menu_f(menu, highlight);
    if(choice != 0) {
      break;
    }
  }
  WINDOW *next_win;
  switch (choice) {
    case 2:
      destroy_win(cs);
      destroy_win(menu);
      setFooter(lw, " [ENTER] - Próximo campo. Em CATEGORIA [SPACE] Para escolher             ");
      wrefresh(lw);
      cs = win_f_new_product();
    break;
    case 4:
    destroy_win(menu);
      destroy_win(cs);
      destroy_win(lw);
      next_win = win_choose();
    break;
  }

  refresh();
  return lw;
}

void print_menu_f(WINDOW* menu, int highlight) {
  int x=3, y=2, i;
  for(i=0; i < n_choices_f; ++i) {
    if(highlight == i + 1) {
      wattron(menu, A_REVERSE);
      mvwprintw(menu, x, y, "%s", choices_f[i]);
      wattroff(menu, A_REVERSE);
    } else {
      mvwprintw(menu, x, y, "%s", choices_f[i]);
    }
    ++x;
  }
  wrefresh(menu);
}
