#ifndef BOARD_PRINT_PLAIN_C
#define BOARD_PRINT_PLAIN_C
#include "board_print_plain.h"
#include <stdio.h>

void print_board() {

  char letter[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

  for (int i = 0; i < 8; i++) {
    printf("%d ", i + 1);
    for (int j = 0; j < 8; j++) {
      printf("[%c] ", point.board[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < 8; i++) {
    printf("   %c", letter[i]);
  }

  printf("\n");
}

#endif //BOARD_PRINT_PLAIN_C