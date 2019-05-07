#include "board_print_plain.h"
#include "board.h"
#include <stdio.h>

int main()
{
  int status = 0;

  info();

  print_board();

  while (1) {
    printf("Ход белых фигур: ");
    input_data(1);
    move_figure();
    print_board();
    status = checkwin(1);
    if (status != 0) {
      break;
    }


    printf("Ход чёрных фигур: ");
    input_data(2);
    move_figure();
    print_board();
    status = checkwin(2);
    if (status != 0) {
      break;
    }
  }

  printf("\n\n   Победил %d игрок!!!", status);

  return 0;

}