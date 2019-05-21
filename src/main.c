#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>

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