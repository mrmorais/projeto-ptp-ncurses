#include "win_f_new_product.h"

void blank_space(WINDOW *lw, int lin, int col, int size) {
  wmove(lw, lin, col);
  wattron(lw, A_REVERSE);
  whline(lw, ' ', size);
  wattroff(lw, A_REVERSE);
}

void clear_buffer(char buffer[100]) {
  int i;
  for (i=0; i<10; i++) {
    buffer[i]=0;
  }
}

WINDOW *win_f_new_product() {
  WINDOW *lw = create_cnewwin(CS_HEIGHT, CS_WIDTH, CS_STARTX, CS_STARTY);

  //Escreve CADASTRAR PRODUTO no topo
  wmove(lw, 1, 2);
  wattron(lw, A_BOLD);
  wprintw(lw, "CADASTRAR PRODUTO");
  wattroff(lw, A_BOLD);

  wmove(lw, 3, 2);
  wprintw(lw, "Código: ");
  blank_space(lw, 3, 11, 10);

  wmove(lw, 3, 24);
  wprintw(lw, "Descrição: ");
  blank_space(lw, 3, 37, 40);

  wmove(lw, 5, 2);
  wprintw(lw, "Fornecedor: ");
  blank_space(lw, 5, 14, 30);

  wmove(lw, 5, 46);
  wprintw(lw, "Quantidade: ");
  blank_space(lw, 5, 58, 5);

  wmove(lw, 5, 67);
  wprintw(lw, "Preço: ");
  blank_space(lw, 5, 75, 10);

  wmove(lw, 7, 2);
  wprintw(lw, "Categoria: ");
  wmove(lw, 7, 14);
  wprintw(lw, "[ ] LIMPEZA");
  wmove(lw, 7, 29);
  wprintw(lw, "[ ] ALIMENTO PERECíVEL");
  wmove(lw, 7, 54);
  wprintw(lw, "[ ] ALIMENTO NãO PERECíVEL");
  wmove(lw, 7, 86);
  wprintw(lw, "[ ] ELETRôNICO");

  wmove(lw, 9, 2);
  wprintw(lw, "Validade: ");
  blank_space(lw, 9, 13, 3);
  wmove(lw, 9, 16);
  wprintw(lw, "/");
  blank_space(lw, 9, 17, 3);
  wmove(lw, 9, 20);
  wprintw(lw, "/");
  blank_space(lw, 9, 21, 5);

  wmove(lw, 11, 2);
  wprintw(lw, "Localização:");
  wmove(lw, 11, 20);
  wprintw(lw, "Corredor ");
  blank_space(lw, 11, 29, 5);
  wmove(lw, 11, 35);
  wprintw(lw, "Prateleira ");
  blank_space(lw, 11, 46, 5);

  wmove(lw, 14, 2);
  wprintw(lw, "SALVAR");

  wmove(lw, 3, 11);

  curs_set(1);
  // move(8, 14);

  char buffer[100];
  int index = 0;
  int field = 1;
  int jump_to_ten = 0;
  int c_x = 3, c_y=11;

  wrefresh(lw);
  while(field < 16) {
    if(jump_to_ten) {
      field = 10;
      c_x = 9;
      c_y = 14;

      jump_to_ten = 0;
      curs_set(1);
      clear_buffer(buffer);
      index = 0;
    }
    int temp = wgetch(lw);


    // wmove(lw, 2,2);
    // wprintw(lw, "%i", field); //debug
    // wprintw(lw, "%i %c %s%c %i", temp, temp, buffer, temp, index); //debug

    if(temp == 127) { //Backspace
      if(index>0) {
        wmove(lw, c_x, --c_y);
        wattron(lw, A_REVERSE);
        wprintw(lw, " ");
        wattroff(lw, A_REVERSE);
        buffer[--index] = 0;
        wmove(lw, c_x, c_y);
      }
    } else if(temp == 10 || temp == 9) { //ENTER || TAB
      //Faz a leitura do buffer direto no Produto TODO

      wmove(lw, 2,2);
      wprintw(lw, "%i", strlen(buffer)); //debug
      if(field==1) { //codigo
        p.codigo = atoi(buffer);
        if(temp==10)
        wmove(lw, 3, 35); //toDesc
      }
      if(field==2) { //desc
        strcpy(p.descricao, buffer);
        if(temp==10)
        wmove(lw, 5, 15); //toForn
      }
      if(field==3) { //forn
        strcpy(p.fornecedor, buffer);
        if(temp==10)
        wmove(lw, 5, 59); //toQnt
      }
      if(field==4) { //quantidade
        p.quantidade = atoi(buffer);
        if(temp==10)
        wmove(lw, 5, 75); //toPrice
      }
      if(field==5) { //preco
        p.preco = atof(buffer);
      }
      if(field==10) { //dia
        p.validade.dia = atoi(buffer);
        if(temp==10)
        wmove(lw, 9, 18); //toMes
      }
      if(field==11) { //mes
        p.validade.mes = atoi(buffer);
        if(temp==10)
        wmove(lw, 9, 22); //toAno
      }
      if(field==12) { //ano
        p.validade.ano = atoi(buffer);
        if(temp==10)
        wmove(lw, 11, 28); //toCorredor
      }
      if(field==13) { //corredor
        p.localizacao.corredor = atoi(buffer);
        if(temp==10)
        wmove(lw, 11, 45); //toPrateleira
      }
      if(field==14) { //prateleira
        p.localizacao.prateleira = atoi(buffer);
      }

      // strcpy(buffer, "");
      clear_buffer(buffer);

      index = 0;
      if(temp == 10)
        field++;
      else
        field--;

      // wmove(lw, 2,2);
      // wprintw(lw, "%i", field); //debug

      switch (field) {
        case 1: //Código
          c_x = 3;
          c_y = 11;
          break;
        case 2: //Descricao
          c_x = 3;
          c_y = 35;
          break;
        case 3: //Fornecedor
          c_x = 5;
          c_y = 15;
          break;
        case 4: //Quantidade
          c_x = 5;
          c_y = 59;
          break;
        case 5: //Preço
          curs_set(1);
          c_x = 5;
          c_y = 75;
          break;
        case 6: //LIMPEZA
          curs_set(0);
          //Clear 7
          wmove(lw, 7, 30);
          wprintw(lw, " ");
          //Ready 6
          wmove(lw, 7, 15);
          wprintw(lw, "o");
          break;
        case 7: //ALIMENTO_P
          curs_set(0);
          //Clear 6
          wmove(lw, 7, 15);
          wprintw(lw, " ");
          //Clear 8
          wmove(lw, 7, 54);
          wprintw(lw, " ");
          //Ready 7
          wmove(lw, 7, 30);
          wprintw(lw, "o");
          break;
        case 8: //ALIMENTO_N_P
          curs_set(0);
          //Clear 7
          wmove(lw, 7, 30);
          wprintw(lw, " ");
          //Clear 9
          wmove(lw, 7, 84);
          wprintw(lw, " ");
          //Ready 8
          wmove(lw, 7, 54);
          wprintw(lw, "o");
          break;
        case 9: //ELETRONICO
          curs_set(0);
          //Clear 8
          wmove(lw, 7, 54);
          wprintw(lw, " ");
          //Ready 9
          wmove(lw, 7, 84);
          wprintw(lw, "o");
          break;
        case 10: //Dia
          curs_set(1);
          c_x = 9;
          c_y = 14;
          break;
        case 11: //Mes
          c_x = 9;
          c_y = 18;
          break;
        case 12: //Ano
          c_x = 9;
          c_y = 22;
          break;
        case 13: //Corredor
          c_x = 11;
          c_y = 28;
          break;
        case 14: //Prateleira
          c_x = 11;
          c_y = 45;
          break;
        case 15: //Enter
          wmove(lw, 14, 2);
          wprintw(lw, "[SALVAR]");
      }
      //continue;
    } else {
      if(field > 5 && field < 10) { //Mutiple choose
        if(temp == 32) { //Space
          //Clear 6
          wmove(lw, 7, 15);
          wprintw(lw, " ");
          //Clear 7
          wmove(lw, 7, 30);
          wprintw(lw, " ");
          //Clear 8
          wmove(lw, 7, 54);
          wprintw(lw, " ");
          //Clear 9
          wmove(lw, 7, 84);
          wprintw(lw, " ");

          switch (field) {
            case 6:
              wmove(lw, 7, 15);
              wprintw(lw, "x");
              p.categoria = 1;
            break;
            case 7:
              wmove(lw, 7, 30);
              wprintw(lw, "x");
              p.categoria = 2;
            break;
            case 8:
              wmove(lw, 7, 54);
              wprintw(lw, "x");
              p.categoria = 3;
            break;
            case 9:
              wmove(lw, 7, 84);
              wprintw(lw, "x");
              p.categoria = 4;
            break;
          }
          jump_to_ten = 1;

          //TODO put on object
        }
      } else {
        buffer[index++] = temp;
        wmove(lw, c_x, c_y++);
        wattron(lw, A_REVERSE);
        wprintw(lw, "%c", temp);
        wattroff(lw, A_REVERSE);
      }
    }

  }
  curs_set(0);
  produto_newProduct(&p); //Save product

  //return to main
  destroy_win(lw);
  WINDOW* next_win;
  next_win = win_funcionario();

  return lw;
}
