#include "win_f_products.h"

WINDOW *win_f_products() {
  WINDOW *lw = create_cnewwin(CS_HEIGHT, CS_WIDTH, CS_STARTX, CS_STARTY); //Products - Local Window

  //Escreve PRODUTOS no topo
  wmove(lw, 1, 2);
  wattron(lw, A_BOLD);
  wprintw(lw, "PRODUTOS");
  wattroff(lw, A_BOLD);
  //Escreve os campos da tabela
  wmove(lw, 2, 2);
  wprintw(lw, "ID");
  wmove(lw, 2, 10);
  wprintw(lw, "Descrição");
  wmove(lw, 2, 40);
  wprintw(lw, "Preço");
  wmove(lw, 2, 53);
  wprintw(lw, "Categoria");
  wmove(lw, 2, 67);
  wprintw(lw, "Fornecedor");
  wmove(lw, 2, 80);
  wprintw(lw, "QNT");
  wmove(lw, 2, 89);
  wprintw(lw, "Validade");
  wmove(lw, 2, 100);
  wprintw(lw, "Local");


  wmove(lw, 3, 2);
  whline(lw, '*', 106);

  Produto products[MAX_LIN];
  produto_getAllProducts(products);
  int i;
  for(i=0; i<MAX_LIN; i++) {
    if(products[i].id != 0) {
      print_produto(lw, i+4, &products[i]);
    }
  }

  wrefresh(lw);

  return lw;
}

void print_produto(WINDOW* ps, int lin, Produto* p) {
  wmove(ps, lin, 2);
  wprintw(ps, "%i", (*p).id);
  wmove(ps, lin, 10);
  wprintw(ps, "%s", (*p).descricao);
  wmove(ps, lin, 40);
  wprintw(ps, "%.2f", (*p).preco);
  wmove(ps, lin, 53);
  switch ((*p).categoria) {
    case 1:
      wprintw(ps, "LIMPEZA");
    break;
    case 2:
      wprintw(ps, "ALIMENTO_P");
    break;
    case 3:
      wprintw(ps, "ALIMENTO_N_P");
    break;
    case 4:
      wprintw(ps, "ELETRONICO");
    break;
  }
  wmove(ps, lin, 67);
  wprintw(ps, "%s", (*p).fornecedor);
  wmove(ps, lin, 80);
  wprintw(ps, "%i", (*p).quantidade);
  wmove(ps, lin, 89);
  if((*p).validade.dia==0 && (*p).validade.mes==0 && (*p).validade.ano==0) {
    wprintw(ps, "NaN");
  } else {
    wprintw(ps, "%i/%i/%i", (*p).validade.dia, (*p).validade.mes, (*p).validade.ano);
  }
  wmove(ps, lin, 100);
  wprintw(ps, "C%i:P%i", (*p).localizacao.corredor, (*p).localizacao.prateleira);
}
