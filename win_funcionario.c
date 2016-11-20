#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include "window.h"
#include "win_funcionario.h"

WINDOW *win_funcionario() {
  WINDOW *lw = create_newwin();

  wmove(lw, 1, 2);
  wprintw(lw, "BUDEGA DO IMD | AREA PARA FUNCIONARIOS");
  wmove(lw, 2, 2);
  // wattron(lw, A_UNDERLINE);
  whline(lw, '-', 143);

  WINDOW *ps = create_cnewwin(33, 110, 5, 4); //Products
  //Escreve PRODUTOS no topo
  wmove(ps, 1, 2);
  wattron(ps, A_BOLD);
  wprintw(ps, "PRODUTOS");
  wattroff(ps, A_BOLD);
  //Escreve os campos da tabela
  wmove(ps, 2, 2);
  wprintw(ps, "ID");
  wmove(ps, 2, 10);
  wprintw(ps, "Descrição");
  wmove(ps, 2, 50);
  wprintw(ps, "Preço");
  wmove(ps, 2, 60);
  wprintw(ps, "Fornecedor");
  wmove(ps, 2, 85);
  wprintw(ps, "QNT");
  wmove(ps, 2, 95);
  wprintw(ps, "Validade");

  wmove(ps, 3, 2);
  whline(ps, '*', 106);


  wrefresh(ps);

  WINDOW *menu = create_cnewwin(33, 32, 5, 115); //Menu

  wrefresh(lw);
  return lw;
}

void print_produto(WINDOW* ps, int lin) {

}
