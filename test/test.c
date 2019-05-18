#include "../src/board.h"
#include "../src/board_print_plain.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <string.h>

int status = 0, i, j;
int x1, x2, Y1, y2;

extern struct Board {
  char board[8][8];
} point;


for (int i = 0; i < 8; i++) {
  for (int j = 0; j < 8; j++) {
    point.board[i][j] = ' ';
  }
}

char input[6];

CTEST(inputdata, chartoint) {
  strcpy(input, "B2-B4"); //обычный ход
  int c1 = charTOint(input, 1);
  
  strcpy(input, "B2xB4"); //ход взятия
  int c2 = charTOint(input, 1);

  strcpy(input, "B2-b3"); //ошибочный ход
  int c3 = charTOint(input, 1);

  strcpy(input, "cDsafab"); //неверный ввод
  int c4 = charTOint(input, 1);

  strcpy(input, "B2-B9"); //выход за пределы доски
  int c5 = charTOint(input, 1);

  const int exp1 = 1;
  const int exp2 = 1;
  const int exp3 = 0;
  const int exp4 = 0;
  const int exp5 = 0;
  
  ASSERT_EQUAL(exp1, c1);
  ASSERT_EQUAL(exp2, c2);
  ASSERT_EQUAL(exp3, c3);
  ASSERT_EQUAL(exp4, c4);
  ASSERT_EQUAL(exp5, c5);
}