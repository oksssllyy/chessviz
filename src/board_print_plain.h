#ifndef BOARD_PRINT_PLAIN_H
#define BOARD_PRINT_PLAIN_H

struct Board {
  char board[8][8];
};

struct Board point;

void make_board();

void print_board();

#endif //BOARD_PRINT_PLAIN_H
