#include "board.h"
#include <stdio.h>
#include <stdlib.h>

char input[6];
int x1, y1, x2, y2;
extern struct Board point;

void infor(){
  printf("      Шахматы\n\n\n");
  printf("Обычный ход (пешка): A2-A3\n
          Взятие фигуры (пешкой): A4xB5\n\n");
  printf("Пример хода белых фигур:\nC2-C4 
          (Ходы белых фигур осуществляются вводом большых букв.)\n
          Пример хода чёрных фигур:\nс7-с5 
          (Ходы чёрных фигур осуществляются вводом маленьких букв.\n\n");
  printf("Для вывода на экран данной информации введите в любой момент 'infor'.\n")
}

void input_data(side) {
  while (1) {
    while (1) {
      fgets(input, 6, stdin);
      if (input == 'infor') {
        infor();
      }
      if (charTOint(input)){
        break;
      }
      printf("Произошла ошибочка. 
              Попробуйте ввести заново ход, уважаемый шамхматист :)")
    }
    if (side == 1){
      if (white_figure()) {
        break;
      } else {
        printf("Произошла ошибочка. 
                Попробуйте ввести заново ход, уважаемый шамхматист :)");
      }
    }
    if (side == 2){
      if (black_figure()) {
        break;
      } else {
        printf("Произошла ошибочка. 
                Попробуйте ввести заново ход, уважаемый шамхматист :)");
      }
    } 
  }
}

int charTOint(input) {
  if ((input[2] != '-') && (input[2] != 'x')) {
    printf("Слушай, ошибочка вышла. Попробуй заново ввести: ");
    return 0;
  }
  if ((input[2] == 'x') && point.board[x2][y2] == ' '){
    printf("Никого нетю, чтобы рубить.\n");
    return 0;
  }
  if ((input[2] == '-') && point.board[x2][y2] != ' '){
    printf("Стой, стой, пожилой. А не пора ли рубить это место, а?\n");
    return 0;
  }

  fgets(input,6,stdin);
  
  int x1 = (int)input[0] - 'A';
  int y1 = (int)input[1] - '1';
  int x2 = (int)input[3] - 'A';
  int y2 = (int)input[4] - '1';
  
  if ((x1 >= 0) && (x1 < 8) && (y1 >= 0) && (y1 < 8) && 
      (x2 >= 0) && (x2 < 8) && (y2 >= 0) && (y2 < 8)) {
    return 1;
  }
  return 0;
}
















