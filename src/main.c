#include "board_print_plain.h"
#include "board.h"
#include <stdio.h>

void make_board() {

  int i, j;

  for (i = 0; i < 8; i++) {
    char cell = ' ';
    switch (i) {
      case 0:
      case 7:
        cell = 'R';
        break;
      case 1:
      case 6:
        cell = 'N';
        break;
      case 2:
      case 5:
        cell = 'B';
        break;
      case 3:
        cell = 'Q';
        break;
      case 4:
        cell = 'K';
        break;
      default:
        break;
    }
    point.board[0][i] = cell;
  }

  for (i = 0; i < 8; i++) {
    point.board[1][i] = 'P';
  }

  for (i = 0; i < 8; i++) {
    for (j = 2; j < 6; j++) {
      point.board[j][i] = ' ';
    }
  }

  for (i = 0; i < 8; i++) {
    char cell = ' ';
    switch (i) {
      case 0:
      case 7:
        cell = 'r';
        break;
      case 1:
      case 6:
        cell = 'n';
        break;
      case 2:
      case 5:
        cell = 'b';
        break;
      case 3:
        cell = 'q';
        break;
      case 4:
        cell = 'k';
        break;
      default:
        break;
    }
    point.board[7][i] = cell;
  }

  for (i = 0; i < 8; i++) {
    point.board[6][i] = 'p';
  }
}

int main() {
  int status = 0;

  information();

  make_board();

  print_board();

  while (1) {
    printf("\nХод белых фигур: ");
    input_data(1);
    move_figure();
    print_board();
    status = checkwin(1);
    if (status != 0) {
      break;
    }


    printf("\nХод чёрных фигур: ");
    input_data(2);
    move_figure();
    print_board();
    status = checkwin(2);
    if (status != 0) {
      break;
    }
  }

  printf("\n\n   Победил %d игрок!!!\n", status);

  return 0;

}