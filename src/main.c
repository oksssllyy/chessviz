#include "board_print_plain.h"
#include "board.h"
#include <stdio.h>

int main()
{
  char input[7];
  int status = 0;

  printf("      Шахматы\n\n\n");
  printf("Обычный ход (пешка): A2-A3\n
          Взятие фигуры (пешкой): A4xB5\n\n");
  printf("Пример хода белых фигур:\nC2-C4 
          (Ходы белых фигур осуществляются вводом большых букв.)\n
          Пример хода чёрных фигур:\nс7-с5 
          (Ходы чёрных фигур осуществляются вводом маленьких букв.\n\n")

  print_board(Board point);

  while (status != 1) {
    printf("Белые ");

  }

}