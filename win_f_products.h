#ifndef _WIN_F_PRODUCTS_H_
#define _WIN_F_PRODUCTS_H_

#include <ncurses.h>
#include <menu.h>
#include <stdlib.h>
#include <string.h>
#include "./class/produto.h"
#include "./class/produtoDAO.h"
#include "window.h"

WINDOW *win_f_products();
void print_produto(WINDOW* ps, int lin, Produto* p);

#endif
