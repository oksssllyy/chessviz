#ifndef BOARD_PRINT_PLAIN_C
#define BOARD_PRINT_PLAIN_C
#include "board_print_plain.h"

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

  print_board(point);
}

void print_board() {

  make_board();

  for (size_t i = 0; i < 8; i++) {
    printf("%ld ", i + 1);
    for (size_t j = 0; j < 8; j++) {
      printf("[%c] ", point.board[i][j]);
    }
    printf("\n");
  }

  for (size_t i = 0; i < 8; i++) {
    printf("   %c", letter[i]);
  }

  printf("\n");
}

#endif //BOARD_PRINT_PLAIN_C