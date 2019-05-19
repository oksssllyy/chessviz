#include "../src/board.h"
#include "../src/board_print_plain.h"
#include "../thirdparty/ctest.h"
#include <stdio.h>
#include <string.h>

int x1, x2, Y1, y2;

extern struct Board point;
void make() {
for (int i = 0; i < 8; i++) {
  for (int j = 0; j < 8; j++) {
    point.board[i][j] = ' ';
  }
}
}

char input[6];

CTEST(inputdata, chartoint) {
  make();
  strcpy(input, "B2-B4"); //обычный ход
  int c1 = charTOint(input, 1);
  
  strcpy(input, "B2xB4"); //ход взятия
  int c2 = charTOint(input, 1);

  strcpy(input, "B2-b3"); //ошибочный ход
  int c3 = charTOint(input, 1);

  strcpy(input, "cDsaf"); //неверный ввод
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
  point.board[Y1+1][x2] = 'r';
  point.board[Y1][x1] = 'P';
  int c14 = white_figure();
  point.board[Y1][x1] = ' ';
  point.board[Y1+1][x2] = ' ';
  
  strcpy(input, "B4-B5"); //ход на занятую клетку
  charTOint(input, 1);
  point.board[Y1+1][x2] = 'r';
  point.board[Y1][x1] = 'P';
  int c15 = white_figure();
  point.board[Y1][x1] = ' ';
  point.board[Y1+1][x2] = ' ';

  const int exp1 = 1;
  const int exp2 = 1;
  const int exp3 = 0;
  const int exp4 = 0;
  const int exp5 = 0;
  const int exp6 = 0;
  const int exp7 = 0;
  const int exp8 = 0;
  const int exp9 = 0;
  const int exp10 = 0;
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
  point.board[Y1+1][x2] = 'n';
  int c3 = white_figure();
  point.board[Y1+1][x2] = ' ';

  strcpy(input, "E5-E2");
  charTOint(input, 1);
  point.board[Y1-1][x2] = 'n';
  int c4 = white_figure();
  point.board[Y1-1][x2] = ' ';

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
  point.board[Y1+1][x2] = 'N';
  int c19 = black_figure();
  point.board[Y1+1][x2] = ' ';

  strcpy(input, "e5-e2");
  charTOint(input, 2);
  point.board[Y1-1][x2] = 'N';
  int c20 = black_figure();
  point.board[Y1-1][x2] = ' ';

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

CTEST(moving, moveknight) {
  /*Ходы белой фигуры*/
  /*Ходы по вертикали*/
  strcpy(input, "E5-E8");
  charTOint(input, 1);
  point.board[Y1][x1] = 'N';
  int c1 = white_figure();

  strcpy(input, "E5-E2");
  charTOint(input, 1);
  int c2 = white_figure();

  /*Ходы по горизонтали*/
  strcpy(input, "E5-A5");
  charTOint(input, 1);
  int c3 = white_figure();

  strcpy(input, "E5-H5");
  charTOint(input, 1);
  int c4 = white_figure();

  /*Ходы по диагонали*/
  strcpy(input, "E5-B8");
  charTOint(input, 1);
  point.board[y2+1][x2-1] = 'p';
  int c5 = white_figure();
  point.board[y2+1][x2-1] = ' ';
  
  strcpy(input, "E5-H2");
  charTOint(input, 1);
  point.board[y2-1][x2+1] = 'p';
  int c6 = white_figure();
  point.board[y2-1][x2+1] = ' ';
  
  strcpy(input, "E5-B2");
  charTOint(input, 1);
  point.board[y2-2][x2-2] = 'p';
  int c7 = white_figure();
  point.board[y2-2][x2-2] = ' ';
  
  strcpy(input, "E5-G7");
  charTOint(input, 1);
  point.board[y2+1][x2+1] = 'p';
  int c8 = white_figure();
  point.board[y2+1][x2+1] = ' ';

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

  /*Верные ходы*/
  strcpy(input, "E5-C4");
  charTOint(input, 1);
  int c13 = white_figure();
  
  strcpy(input, "E5-C6");
  charTOint(input, 1);
  int c14 = white_figure();
  
  strcpy(input, "E5-G4");
  charTOint(input, 1);
  int c15 = white_figure();
  
  strcpy(input, "E5-G6");
  charTOint(input, 1);
  int c16 = white_figure();
  
  strcpy(input, "E5-D7");
  charTOint(input, 1);
  int c17 = white_figure();
  
  strcpy(input, "E5-F7");
  charTOint(input, 1);
  int c18 = white_figure();
  
  strcpy(input, "E5-F3");
  charTOint(input, 1);
  int c19 = white_figure();
  
  strcpy(input, "E5-D3");
  charTOint(input, 1);
  int c20 = white_figure();  

  /*Ходы взятия чужой фигуры*/
  strcpy(input, "E5xC4");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c21 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xC6");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c22 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xG4");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c23 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xG6");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c24 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xD7");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c25 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xF7");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c26 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xF3");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c27 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xD3");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c28 = white_figure(); 
  point.board[y2][x2] = ' '; 

  /*Ошибочные ходы взятия*/
  strcpy(input, "E5xC3");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c29 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xF8");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c30 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xG7");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c31 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xF1");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c32 = white_figure();
  point.board[y2][x2] = ' ';
  point.board[Y1][x1] = ' ';

  /*Ходы чёрной фигуры*/
  /*Ходы по вертикали*/
  strcpy(input, "e5-e8");
  charTOint(input, 2);
  point.board[Y1][x1] = 'n';
  int c33 = black_figure();

  strcpy(input, "e5-e2");
  charTOint(input, 2);
  int c34 = black_figure();

  /*Ходы по горизонтали*/
  strcpy(input, "e5-a5");
  charTOint(input, 2);
  int c35 = black_figure();

  strcpy(input, "e5-h5");
  charTOint(input, 2);
  int c36 = black_figure();

  /*Ходы по диагонали*/
  strcpy(input, "e5-b8");
  charTOint(input, 2);
  point.board[y2+1][x2-1] = 'P';
  int c37 = black_figure();
  point.board[y2+1][x2-1] = ' ';
  
  strcpy(input, "e5-h2");
  charTOint(input, 2);
  point.board[y2-1][x2+1] = 'P';
  int c38 = black_figure();
  point.board[y2-1][x2+1] = ' ';
  
  strcpy(input, "e5-b2");
  charTOint(input, 2);
  point.board[y2-2][x2-2] = 'P';
  int c39 = black_figure();
  point.board[y2-2][x2-2] = ' ';
  
  strcpy(input, "e5-g7");
  charTOint(input, 2);
  point.board[y2+1][x2+1] = 'P';
  int c40 = black_figure();
  point.board[y2+1][x2+1] = ' ';

  strcpy(input, "e5-c7");
  charTOint(input, 2);
  int c41 = black_figure();
  
  strcpy(input, "e5-g3");
  charTOint(input, 2);
  int c42 = black_figure();
  
  strcpy(input, "e5-g7");
  charTOint(input, 2);
  int c43 = black_figure();

  strcpy(input, "e5-c3");
  charTOint(input, 2);
  int c44 = black_figure();

  /*Верные ходы*/
  strcpy(input, "e5-c4");
  charTOint(input, 2);
  int c45 = black_figure();
  
  strcpy(input, "e5-c6");
  charTOint(input, 2);
  int c46 = black_figure();
  
  strcpy(input, "e5-g4");
  charTOint(input, 2);
  int c47 = black_figure();
  
  strcpy(input, "e5-g6");
  charTOint(input, 2);
  int c48 = black_figure();
  
  strcpy(input, "e5-d7");
  charTOint(input, 2);
  int c49 = black_figure();
  
  strcpy(input, "e5-f7");
  charTOint(input, 2);
  int c50 = black_figure();
  
  strcpy(input, "e5-f3");
  charTOint(input, 2);
  int c51 = black_figure();
  
  strcpy(input, "e5-d3");
  charTOint(input, 2);
  int c52 = black_figure();  

  /*Ходы взятия чужой фигуры*/
  strcpy(input, "e5xc4");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c53 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xc6");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c54 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xg4");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c55 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xg6");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c56 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xd7");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c57 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xf7");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c58 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xf3");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c59 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xd3");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c60 = black_figure(); 
  point.board[y2][x2] = ' '; 

  /*Ошибочные ходы взятия*/
  strcpy(input, "e5xc3");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c61 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xf8");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c62 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xg7");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c63 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xf1");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c64 = black_figure();
  point.board[y2][x2] = ' ';
  point.board[Y1][x1] = ' ';


  const int exp1 = 0;
  const int exp2 = 0;
  const int exp3 = 0;
  const int exp4 = 0;
  const int exp5 = 0;
  const int exp6 = 0;
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
  const int exp19 = 1;
  const int exp20 = 1;
  const int exp21 = 1;
  const int exp22 = 1;
  const int exp23 = 1;
  const int exp24 = 1;
  const int exp25 = 1;
  const int exp26 = 1;
  const int exp27 = 1;
  const int exp28 = 1;
  const int exp29 = 0;
  const int exp30 = 0;
  const int exp31 = 0;
  const int exp32 = 0;
  const int exp33 = 0;
  const int exp34 = 0;
  const int exp35 = 0;
  const int exp36 = 0;
  const int exp37 = 0;
  const int exp38 = 0;
  const int exp39 = 0;
  const int exp40 = 0;
  const int exp41 = 0;
  const int exp42 = 0;
  const int exp43 = 0;
  const int exp44 = 0;
  const int exp45 = 1;
  const int exp46 = 1;
  const int exp47 = 1;
  const int exp48 = 1;
  const int exp49 = 1;
  const int exp50 = 1;
  const int exp51 = 1;
  const int exp52 = 1;
  const int exp53 = 1;
  const int exp54 = 1;
  const int exp55 = 1;
  const int exp56 = 1;
  const int exp57 = 1;
  const int exp58 = 1;
  const int exp59 = 1;
  const int exp60 = 1;
  const int exp61 = 0;
  const int exp62 = 0;
  const int exp63 = 0;
  const int exp64 = 0;
  
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
  ASSERT_EQUAL(exp33, c33);
  ASSERT_EQUAL(exp34, c34);
  ASSERT_EQUAL(exp35, c35);
  ASSERT_EQUAL(exp36, c36);  
  ASSERT_EQUAL(exp37, c37);
  ASSERT_EQUAL(exp38, c38);
  ASSERT_EQUAL(exp39, c39);
  ASSERT_EQUAL(exp40, c40);
  ASSERT_EQUAL(exp41, c41);
  ASSERT_EQUAL(exp42, c42);
  ASSERT_EQUAL(exp43, c43);
  ASSERT_EQUAL(exp44, c44);
  ASSERT_EQUAL(exp45, c45);
  ASSERT_EQUAL(exp46, c46);
  ASSERT_EQUAL(exp47, c47);
  ASSERT_EQUAL(exp48, c48);
  ASSERT_EQUAL(exp49, c49);
  ASSERT_EQUAL(exp50, c50);
  ASSERT_EQUAL(exp51, c51);
  ASSERT_EQUAL(exp52, c52);
  ASSERT_EQUAL(exp53, c53);
  ASSERT_EQUAL(exp54, c54);
  ASSERT_EQUAL(exp55, c55);
  ASSERT_EQUAL(exp56, c56);
  ASSERT_EQUAL(exp57, c57);
  ASSERT_EQUAL(exp58, c58);
  ASSERT_EQUAL(exp59, c59);
  ASSERT_EQUAL(exp60, c60);
  ASSERT_EQUAL(exp61, c61);
  ASSERT_EQUAL(exp62, c62);
  ASSERT_EQUAL(exp63, c63);
  ASSERT_EQUAL(exp64, c64);
}

CTEST(moving, movebishop) {
  /*Ходы белой фигуры*/
  /*Ходы по вертикали*/
  strcpy(input, "E5-E8");
  charTOint(input, 1);
  point.board[Y1][x1] = 'B';
  int c1 = white_figure();

  strcpy(input, "E5-E2");
  charTOint(input, 1);
  int c2 = white_figure();

  /*Ходы по горизонтали*/
  strcpy(input, "E5-A5");
  charTOint(input, 1);
  int c3 = white_figure();

  strcpy(input, "E5-H5");
  charTOint(input, 1);
  int c4 = white_figure();

  /*Ходы по диагонали*/
  strcpy(input, "E5-B8");
  charTOint(input, 1);
  point.board[Y1+1][x1-1] = 'p';
  int c5 = white_figure();
  point.board[Y1+1][x1-1] = ' ';
  
  strcpy(input, "E5-H2");
  charTOint(input, 1);
  point.board[Y1-1][x1+1] = 'p';
  int c6 = white_figure();
  point.board[Y1-1][x1+1] = ' ';
  
  strcpy(input, "E5-B2");
  charTOint(input, 1);
  point.board[Y1-2][x1-2] = 'p';
  int c7 = white_figure();
  point.board[Y1-2][x1-2] = ' ';
  
  strcpy(input, "E5-G7");
  charTOint(input, 1);
  point.board[Y1+2][x1+2] = 'p';
  int c8 = white_figure();
  point.board[Y1+2][x1+2] = ' ';

  /*Верные ходы*/
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

  /*Неправильные ходы*/
  strcpy(input, "E5-C4");
  charTOint(input, 1);
  int c13 = white_figure();
  
  strcpy(input, "E5-C6");
  charTOint(input, 1);
  int c14 = white_figure();
  
  strcpy(input, "E5-G4");
  charTOint(input, 1);
  int c15 = white_figure();
  
  strcpy(input, "E5-G6");
  charTOint(input, 1);
  int c16 = white_figure();

  strcpy(input, "E5-G9");
  charTOint(input, 1);
  int c17 = white_figure();

  /*Ходы взятия чужих фигур*/
  strcpy(input, "E5xC7");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c18 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xG3");
  charTOint(input, 1);
  point.board[y2][x2] = 'n';
  int c19 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xG7");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c20 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xC3");
  charTOint(input, 1);
  point.board[y2][x2] = 'r';
  int c21 = white_figure();
  point.board[y2][x2] = ' ';
  point.board[Y1][x1] = ' ';


  /*Ходы чёрной фигуры*/
  /*Ходы по вертикали*/
  strcpy(input, "e5-e8");
  charTOint(input, 2);
  point.board[Y1][x1] = 'b';
  int c22 = black_figure();

  strcpy(input, "e5-e2");
  charTOint(input, 2);
  int c23 = black_figure();

  /*Ходы по горизонтали*/
  strcpy(input, "e5-a5");
  charTOint(input, 2);
  int c24 = black_figure();

  strcpy(input, "e5-h5");
  charTOint(input, 2);
  int c25 = black_figure();

  /*Ходы по диагонали*/
  strcpy(input, "e5-b8");
  charTOint(input, 2);
  point.board[Y1+1][x1-1] = 'P';
  int c26 = black_figure();
  point.board[Y1+1][x1-1] = ' ';
  
  strcpy(input, "e5-h2");
  charTOint(input, 2);
  point.board[Y1-1][x1+1] = 'P';
  int c27 = black_figure();
  point.board[Y1-1][x1+1] = ' ';
  
  strcpy(input, "e5-b2");
  charTOint(input, 2);
  point.board[Y1-1][x1-1] = 'P';
  int c28 = black_figure();
  point.board[Y1-1][x1-1] = ' ';
  
  strcpy(input, "e5-g7");
  charTOint(input, 2);
  point.board[Y1+1][x1+1] = 'P';
  int c29 = black_figure();
  point.board[Y1+1][x1+1] = ' ';

  /*Верные ходы*/
  strcpy(input, "e5-c7");
  charTOint(input, 2);
  int c30 = black_figure();
  
  strcpy(input, "e5-g3");
  charTOint(input, 2);
  int c31 = black_figure();
  
  strcpy(input, "e5-g7");
  charTOint(input, 2);
  int c32 = black_figure();

  strcpy(input, "e5-c3");
  charTOint(input, 2);
  int c33 = black_figure();

  /*Неправильные ходы*/
  strcpy(input, "e5-c4");
  charTOint(input, 2);
  int c34 = black_figure();
  
  strcpy(input, "e5-c6");
  charTOint(input, 2);
  int c35 = black_figure();
  
  strcpy(input, "e5-g4");
  charTOint(input, 2);
  int c36 = black_figure();
  
  strcpy(input, "e5-g6");
  charTOint(input, 2);
  int c37 = black_figure();

  strcpy(input, "e5-g9");
  charTOint(input, 2);
  int c38 = black_figure();

  /*Ходы взятия чужих фигур*/
  strcpy(input, "e5xc7");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c39 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xg3");
  charTOint(input, 2);
  point.board[y2][x2] = 'N';
  int c40 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xg7");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c41 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xc3");
  charTOint(input, 2);
  point.board[y2][x2] = 'R';
  int c42 = black_figure();
  point.board[y2][x2] = ' ';
  point.board[Y1][x1] = ' ';
  

  const int exp1 = 0;
  const int exp2 = 0;
  const int exp3 = 0;
  const int exp4 = 0;
  const int exp5 = 0;
  const int exp6 = 0;
  const int exp7 = 0;
  const int exp8 = 0;
  const int exp9 = 1;
  const int exp10 = 1;
  const int exp11 = 1;
  const int exp12 = 1;
  const int exp13 = 0;
  const int exp14 = 0;
  const int exp15 = 0;
  const int exp16 = 0;
  const int exp17 = 0;
  const int exp18 = 1;
  const int exp19 = 1;
  const int exp20 = 1;
  const int exp21 = 1;
  const int exp22 = 0;
  const int exp23 = 0;
  const int exp24 = 0;
  const int exp25 = 0;
  const int exp26 = 0;
  const int exp27 = 0;
  const int exp28 = 0;
  const int exp29 = 0;
  const int exp30 = 1;
  const int exp31 = 1;
  const int exp32 = 1;
  const int exp33 = 1;
  const int exp34 = 0;
  const int exp35 = 0;
  const int exp36 = 0;
  const int exp37 = 0;
  const int exp38 = 0;
  const int exp39 = 1;
  const int exp40 = 1;
  const int exp41 = 1;
  const int exp42 = 1;

  
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
  ASSERT_EQUAL(exp33, c33);
  ASSERT_EQUAL(exp34, c34);
  ASSERT_EQUAL(exp35, c35);
  ASSERT_EQUAL(exp36, c36);  
  ASSERT_EQUAL(exp37, c37);
  ASSERT_EQUAL(exp38, c38);
  ASSERT_EQUAL(exp39, c39);
  ASSERT_EQUAL(exp40, c40);
  ASSERT_EQUAL(exp41, c41);
  ASSERT_EQUAL(exp42, c42);
}

CTEST(moving, queen) {
  /*Ходы белой фигуры*/
  /*Ходы по вертикали*/
  strcpy(input, "E5-E8");
  charTOint(input, 1);
  point.board[Y1][x1] = 'Q';
  int c1 = white_figure();

  strcpy(input, "E5-E2");
  charTOint(input, 1);
  int c2 = white_figure();

  strcpy(input, "E5-E7");
  charTOint(input, 1);
  point.board[Y1+1][x2] = 'n';
  int c3 = white_figure();
  point.board[Y1+1][x2] = ' ';

  strcpy(input, "E5-E2");
  charTOint(input, 1);
  point.board[Y1-1][x2] = 'n';
  int c4 = white_figure();
  point.board[Y1-1][x2] = ' ';

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

  /*Ходы по диагонали(ходы через фигуру)*/
  strcpy(input, "E5-B8");
  charTOint(input, 1);
  point.board[Y1+1][x1-1] = 'p';
  int c9 = white_figure();
  point.board[Y1+1][x1-1] = ' ';
  
  strcpy(input, "E5-H2");
  charTOint(input, 1);
  point.board[Y1-1][x1+1] = 'p';
  int c10 = white_figure();
  point.board[Y1-1][x1+1] = ' ';
  
  strcpy(input, "E5-B2");
  charTOint(input, 1);
  point.board[Y1-2][x1-2] = 'p';
  int c11 = white_figure();
  point.board[Y1-2][x1-2] = ' ';
  
  strcpy(input, "E5-G7");
  charTOint(input, 1);
  point.board[Y1+2][x1+2] = 'p';
  int c12 = white_figure();
  point.board[Y1+2][x1+2] = ' ';

  /*Ходы по диагонали(верные ходы)*/
  strcpy(input, "E5-C7");
  charTOint(input, 1);
  int c13 = white_figure();
  
  strcpy(input, "E5-G3");
  charTOint(input, 1);
  int c14 = white_figure();
  
  strcpy(input, "E5-G7");
  charTOint(input, 1);
  int c15 = white_figure();

  strcpy(input, "E5-C3");
  charTOint(input, 1);
  int c16 = white_figure();

  /*Неправильные ходы*/
  strcpy(input, "E5-C4");
  charTOint(input, 1);
  int c17 = white_figure();
  
  strcpy(input, "E5-C6");
  charTOint(input, 1);
  int c18 = white_figure();
  
  strcpy(input, "E5-G4");
  charTOint(input, 1);
  int c19 = white_figure();
  
  strcpy(input, "E5-G6");
  charTOint(input, 1);
  int c20 = white_figure();

  strcpy(input, "E5-G9");
  charTOint(input, 1);
  int c21 = white_figure();

  /*Ходы взятия чужих фигур*/
  strcpy(input, "E5xE7");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c22 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xE2");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c23 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xB5");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c24 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xH5");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c25 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xC7");
  charTOint(input, 1);
  point.board[y2][x2] = 'p';
  int c26 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xG3");
  charTOint(input, 1);
  point.board[y2][x2] = 'n';
  int c27 = white_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "E5xG7");
  charTOint(input, 1);
  point.board[y2][x2] = 'q';
  int c28 = white_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "E5xC3");
  charTOint(input, 1);
  point.board[y2][x2] = 'r';
  int c29 = white_figure();
  point.board[y2][x2] = ' ';
  point.board[Y1][x1] = ' ';

  /*Ходы чёрной фигуры*/
  /*Ходы по вертикали*/
  strcpy(input, "e5-e8");
  charTOint(input, 2);
  point.board[Y1][x1] = 'q';
  int c30 = black_figure();

  strcpy(input, "e5-e2");
  charTOint(input, 2);
  int c31 = black_figure();

  strcpy(input, "e5-e7");
  charTOint(input, 2);
  point.board[Y1+1][x2] = 'N';
  int c32 = black_figure();
  point.board[Y1+1][x2] = ' ';

  strcpy(input, "e5-e2");
  charTOint(input, 2);
  point.board[Y1-1][x2] = 'N';
  int c33 = black_figure();
  point.board[Y1-1][x2] = ' ';

  /*Ходы по горизонтали*/
  strcpy(input, "e5-a5");
  charTOint(input, 2);
  int c34 = black_figure();

  strcpy(input, "e5-h5");
  charTOint(input, 2);
  int c35 = black_figure();

  strcpy(input, "e5-a5");
  charTOint(input, 2);
  point.board[y2][x2+1] = 'R';
  int c36 = black_figure();
  point.board[y2][x2+1] = ' ';

  strcpy(input, "e5-h5");
  charTOint(input, 2);
  point.board[y2][x2-1] = 'R';
  int c37 = black_figure();
  point.board[y2][x2-1] = ' ';

  /*Ходы по диагонали*/
  strcpy(input, "e5-b8");
  charTOint(input, 2);
  point.board[Y1+1][x1-1] = 'P';
  int c38 = black_figure();
  point.board[Y1+1][x1-1] = ' ';
  
  strcpy(input, "e5-h2");
  charTOint(input, 2);
  point.board[Y1-1][x1+1] = 'P';
  int c39 = black_figure();
  point.board[Y1-1][x1+1] = ' ';
  
  strcpy(input, "e5-b2");
  charTOint(input, 2);
  point.board[Y1-1][x1-1] = 'P';
  int c40 = black_figure();
  point.board[Y1-1][x1-1] = ' ';
  
  strcpy(input, "e5-g7");
  charTOint(input, 2);
  point.board[Y1+1][x1+1] = 'P';
  int c41 = black_figure();
  point.board[Y1+1][x1+1] = ' ';

  /*Верные ходы*/
  strcpy(input, "e5-c7");
  charTOint(input, 2);
  int c42 = black_figure();
  
  strcpy(input, "e5-g3");
  charTOint(input, 2);
  int c43 = black_figure();
  
  strcpy(input, "e5-g7");
  charTOint(input, 2);
  int c44 = black_figure();

  strcpy(input, "e5-c3");
  charTOint(input, 2);
  int c45 = black_figure();

  /*Неправильные ходы*/
  strcpy(input, "e5-c4");
  charTOint(input, 2);
  int c46 = black_figure();
  
  strcpy(input, "e5-c6");
  charTOint(input, 2);
  int c47 = black_figure();
  
  strcpy(input, "e5-g4");
  charTOint(input, 2);
  int c48 = black_figure();
  
  strcpy(input, "e5-g6");
  charTOint(input, 2);
  int c49 = black_figure();

  strcpy(input, "e5-g9");
  charTOint(input, 2);
  int c50 = black_figure();

  /*Ходы взятия чужих фигур*/
  strcpy(input, "e5xe7");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c51 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xe2");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c52 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xb5");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c53 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xh5");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c54 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xc7");
  charTOint(input, 2);
  point.board[y2][x2] = 'P';
  int c55 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xg3");
  charTOint(input, 2);
  point.board[y2][x2] = 'N';
  int c56 = black_figure();
  point.board[y2][x2] = ' ';
  
  strcpy(input, "e5xg7");
  charTOint(input, 2);
  point.board[y2][x2] = 'Q';
  int c57 = black_figure();
  point.board[y2][x2] = ' ';

  strcpy(input, "e5xc3");
  charTOint(input, 2);
  point.board[y2][x2] = 'R';
  int c58 = black_figure();
  point.board[y2][x2] = ' ';
  point.board[Y1][x1] = ' ';

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
  const int exp17 = 0;
  const int exp18 = 0;
  const int exp19 = 0;
  const int exp20 = 0;
  const int exp21 = 0;
  const int exp22 = 1;
  const int exp23 = 1;
  const int exp24 = 1;
  const int exp25 = 1;
  const int exp26 = 1;
  const int exp27 = 1;
  const int exp28 = 1;
  const int exp29 = 1;
  const int exp30 = 1;
  const int exp31 = 1;
  const int exp32 = 0;
  const int exp33 = 0;
  const int exp34 = 1;
  const int exp35 = 1;
  const int exp36 = 0;
  const int exp37 = 0;
  const int exp38 = 0;
  const int exp39 = 0;
  const int exp40 = 0;
  const int exp41 = 0;
  const int exp42 = 1;
  const int exp43 = 1;
  const int exp44 = 1;
  const int exp45 = 1;
  const int exp46 = 0;
  const int exp47 = 0;
  const int exp48 = 0;
  const int exp49 = 0;
  const int exp50 = 0;
  const int exp51 = 1;
  const int exp52 = 1;
  const int exp53 = 1;
  const int exp54 = 1;
  const int exp55 = 1;
  const int exp56 = 1;
  const int exp57 = 1;
  const int exp58 = 1;

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
  ASSERT_EQUAL(exp33, c33);
  ASSERT_EQUAL(exp34, c34);
  ASSERT_EQUAL(exp35, c35);
  ASSERT_EQUAL(exp36, c36);  
  ASSERT_EQUAL(exp37, c37);
  ASSERT_EQUAL(exp38, c38);
  ASSERT_EQUAL(exp39, c39);
  ASSERT_EQUAL(exp40, c40);
  ASSERT_EQUAL(exp41, c41);
  ASSERT_EQUAL(exp42, c42);
  ASSERT_EQUAL(exp43, c43);
  ASSERT_EQUAL(exp44, c44);
  ASSERT_EQUAL(exp45, c45);
  ASSERT_EQUAL(exp46, c46);
  ASSERT_EQUAL(exp47, c47);
  ASSERT_EQUAL(exp48, c48);
  ASSERT_EQUAL(exp49, c49);
  ASSERT_EQUAL(exp50, c50);
  ASSERT_EQUAL(exp51, c51);
  ASSERT_EQUAL(exp52, c52);
  ASSERT_EQUAL(exp53, c53);
  ASSERT_EQUAL(exp54, c54);
  ASSERT_EQUAL(exp55, c55);
  ASSERT_EQUAL(exp56, c56);
  ASSERT_EQUAL(exp57, c57);
  ASSERT_EQUAL(exp58, c58);
}