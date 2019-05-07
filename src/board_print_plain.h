#ifndef BOARD_PRINT_PLAIN_H
#define BOARD_PRINT_PLAIN_H
#include "board.h"

struct Board {
  char board[8][8];
};

struct Board point;

char letter[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

void print_board();

void make_board();

#endif //BOARD_PRINT_PLAIN_H