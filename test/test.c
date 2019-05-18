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

CTEST(moving, moverook) {
  /*Ходы белой ладьи*/
  /*Ходы по вертикали*/
  strcpy(input, "E5-E8");
  charTOint(input, 1);
  point.board[Y1][x1] = 'R';
  int c1 = white_figure();

  strcpy(input, "E5-E2");
  charTOint(input, 1);
  int c2 = white_figure();

  strcpy(input, "E5-E7");
  charTOint(input, 1);
  point.board[y2-1][x2] = 'n';
  int c3 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5-E2");
  charTOint(input, 1);
  point.board[y2+1][x2] = 'n';
  int c4 = white_figure();
  point.board[y2][x2] = ' ';

  /*Ходы по горизонтали*/
  strcpy(input, "E5-A5");
  charTOint(input, 1);
  int c5 = white_figure();

  strcpy(input, "E5-H5");
  charTOint(input, 1);
  int c6 = white_figure();

  strcpy(input, "E5-A5");
  charTOint(input, 1);
  point.board[y2][x2+1] = 'r';
  int c7 = white_figure();
  point.board[y2][x2+1] = ' ';

  strcpy(input, "E5-H5");
  charTOint(input, 1);
  point.board[y2][x2-1] = 'r';
  int c8 = white_figure();
  point.board[y2][x2-1] = ' ';

  /*Ходы по диагонали*/
  strcpy(input, "E5-C7");
  charTOint(input, 1);
  int c9 = white_figure();
  
  strcpy(input, "E5-G3");
  charTOint(input, 1);
  int c10 = white_figure();
  
  strcpy(input, "E5-G7");
  charTOint(input, 1);
  int c11 = white_figure();

  strcpy(input, "E5-C3");
  charTOint(input, 1);
  int c12 = white_figure();

  /*Ходы взятия чужих фигур*/
  strcpy(input, "E5xE7");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c13 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xE2");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c14 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xB5");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c15 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xH5");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c16 = white_figure();
  point.board[y2][x2] = ' ';

  /*Ходы чёрной ладьи*/
  /*Ходы по вертикали*/
  strcpy(input, "e5-e8");
  charTOint(input, 2);
  point.board[Y1][x1] = 'r';
  int c17 = black_figure();

  strcpy(input, "e5-e2");
  charTOint(input, 2);
  int c18 = black_figure();

  strcpy(input, "e5-e7");
  charTOint(input, 2);
  point.board[y2-1][x2] = 'N';
  int c19 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5-e2");
  charTOint(input, 2);
  point.board[y2+1][x2] = 'N';
  int c20 = black_figure();
  point.board[y2][x2] = ' ';

  /*Ходы по горизонтали*/
  strcpy(input, "e5-a5");
  charTOint(input, 2);
  int c21 = black_figure();

  strcpy(input, "e5-h5");
  charTOint(input, 2);
  int c22 = black_figure();

  strcpy(input, "e5-a5");
  charTOint(input, 2);
  point.board[y2][x2+1] = 'R';
  int c23 = black_figure();
  point.board[y2][x2+1] = ' ';

  strcpy(input, "e5-h5");
  charTOint(input, 2);
  point.board[y2][x2-1] = 'R';
  int c24 = black_figure();
  point.board[y2][x2-1] = ' ';

  /*Ходы по диагонали*/
  strcpy(input, "e5-c7");
  charTOint(input, 2);
  int c25 = black_figure();
  
  strcpy(input, "e5-g3");
  charTOint(input, 2);
  int c26 = black_figure();
  
  strcpy(input, "e5-g7");
  charTOint(input, 2);
  int c27 = black_figure();

  strcpy(input, "e5-c3");
  charTOint(input, 2);
  int c28 = black_figure();

  /*Ходы взятия чужих фигур*/
  strcpy(input, "e5xe7");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c29 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xe2");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c30 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xb5");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c31 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xh5");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c32 = black_figure();
  point.board[y2][x2] = ' ';

  const int exp1 = 1;
  const int exp2 = 1;
  const int exp3 = 0;
  const int exp4 = 0;
  const int exp5 = 1;
  const int exp6 = 1;
  const int exp7 = 0;
  const int exp8 = 0;
  const int exp9 = 0;
  const int exp10 = 0;
  const int exp11 = 0;
  const int exp12 = 0;
  const int exp13 = 1;
  const int exp14 = 1;
  const int exp15 = 1;
  const int exp16 = 1;
  const int exp17 = 1;
  const int exp18 = 1;
  const int exp19 = 0;
  const int exp20 = 0;
  const int exp21 = 1;
  const int exp22 = 1;
  const int exp23 = 0;
  const int exp24 = 0;
  const int exp25 = 0;
  const int exp26 = 0;
  const int exp27 = 0;
  const int exp28 = 0;
  const int exp29 = 1;
  const int exp30 = 1;
  const int exp31 = 1;
  const int exp32 = 1;
  
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
  ASSERT_EQUAL(exp16, c16);
  ASSERT_EQUAL(exp17, c17);
  ASSERT_EQUAL(exp18, c18);
  ASSERT_EQUAL(exp19, c19);
  ASSERT_EQUAL(exp20, c20);
  ASSERT_EQUAL(exp21, c21);
  ASSERT_EQUAL(exp22, c22);
  ASSERT_EQUAL(exp23, c23);
  ASSERT_EQUAL(exp24, c24);
  ASSERT_EQUAL(exp25, c25);
  ASSERT_EQUAL(exp26, c26);
  ASSERT_EQUAL(exp27, c27);
  ASSERT_EQUAL(exp28, c28);
  ASSERT_EQUAL(exp29, c29);
  ASSERT_EQUAL(exp30, c30);
  ASSERT_EQUAL(exp31, c31);
  ASSERT_EQUAL(exp32, c32);
}