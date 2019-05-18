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

CTEST(moving, movepawnWHITE) {
  strcpy(input, "B2-B3"); //первый ход на одну клетку
  charTOint(input, 1);
  point.board[Y1][x1] = 'P';
  int c1 = white_figure();

  strcpy(input, "B2-B4"); //первый ход через клетку
  charTOint(input, 1);
  int c2 = white_figure();

  strcpy(input, "B2-B5"); //первый ход через 2 клетки
  charTOint(input, 1);
  point.board[Y1][x1] = 'P';
  int c3 = white_figure();

  strcpy(input, "B2-C3"); //ход по диагонали вправо
  charTOint(input, 1);
  int c4 = white_figure();

  strcpy(input, "B2-A3"); //ход по диагонали влево
  charTOint(input, 1);
  int c5 = white_figure();

  strcpy(input, "B2-B1"); //первый ход (назад) 
  charTOint(input, 1);
  int c6 = white_figure();
  point.board[Y1][x1] = ' ';

  strcpy(input, "A4-A6"); //ход через одну клетку 
  charTOint(input, 1);
  point.board[Y1][x1] = 'P';
  int c7 = white_figure();
  point.board[Y1][x1] = ' ';

  strcpy(input, "A4-B4"); //ход по горизонтали вправо
  charTOint(input, 1);
  point.board[Y1][x1] = 'P';
  int c8 = white_figure();
  point.board[Y1][x1] = ' ';

  strcpy(input, "B4-A4"); //ход по горизонтали влево 
  charTOint(input, 1);
  point.board[Y1][x1] = 'P';
  int c9 = white_figure();
  point.board[Y1][x1] = ' ';

  strcpy(input, "B5-B9"); //выход за пределы
  charTOint(input, 1);
  point.board[Y1][x1] = 'P';
  int c10 = white_figure();
  point.board[Y1][x1] = ' ';

  strcpy(input, "A4xB5"); //ход взятия
  charTOint(input, 1);
  point.board[y2][x2] = 'r';
  point.board[Y1][x1] = 'P';
  int c11 = white_figure();
  point.board[Y1][x1] = ' ';
  point.board[y2][x2] = ' ';

  strcpy(input, "D4-C5"); //ход взятия
  charTOint(input, 1);
  point.board[y2][x2] = 'r';
  point.board[Y1][x1] = 'P';
  int c12 = white_figure();
  point.board[Y1][x1] = ' ';
  point.board[y2][x2] = ' ';

  strcpy(input, "B4-B3"); //ход назад
  charTOint(input, 1);
  point.board[Y1][x1] = 'P';
  int c13 = white_figure();
  point.board[Y1][x1] = ' ';

  strcpy(input, "B2-B4"); //первый ход через фигуру
  charTOint(input, 1);
  point.board[Y+1][x2] = 'r';
  point.board[Y1][x1] = 'P';
  int c14 = white_figure();
  point.board[Y1][x1] = ' ';
  point.board[Y+1][x2] = ' ';
  
  strcpy(input, "B4-B5"); //ход на занятую клетку
  charTOint(input, 1);
  point.board[Y+1][x2] = 'r';
  point.board[Y1][x1] = 'P';
  int c15 = white_figure();
  point.board[Y1][x1] = ' ';
  point.board[Y+1][x2] = ' ';

  const int exp1 = 1;
  const int exp2 = 1;
  const int exp3 = 0;
  const int exp4 = 0;
  const int exp5 = 0;
  const int exp6 = 0;
  const int exp7 = 0;
  const int exp8 = 0;
  const int exp9 = 0;
  const int exp10 = 1;
  const int exp11 = 1;
  const int exp12 = 0;
  const int exp13 = 0;
  const int exp14 = 0;
  const int exp15 = 0;
  
  ASSERT_EQUAL(exp1, c1);
  ASSERT_EQUAL(exp2, c2);
  ASSERT_EQUAL(exp3, c3);
  ASSERT_EQUAL(exp4, c4);  
  ASSERT_EQUAL(exp5, c5);
  ASSERT_EQUAL(exp6, c6);
  ASSERT_EQUAL(exp7, c7);
  ASSERT_EQUAL(exp8, c8);
  ASSERT_EQUAL(exp9, c9);
  ASSERT_EQUAL(exp10, c10);
  ASSERT_EQUAL(exp11, c11);
  ASSERT_EQUAL(exp12, c12);
  ASSERT_EQUAL(exp13, c13);
  ASSERT_EQUAL(exp14, c14);
  ASSERT_EQUAL(exp15, c15);
}

CTEST(moving, moverook)