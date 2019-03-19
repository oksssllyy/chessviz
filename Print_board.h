#ifndef PRINT_BOARD_H
#define PRINT_BOARD_H
#include "board.h"

void print_board(struct Board point) {
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
#endif //PRINT_BOARD_H
