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
      if ((input[2] != '-') && (input[2] != 'x')) {
        printf("Слушай, ошибочка вышла. Попробуй заново ввести: ");
        return 0;
      }
      if ((input[2] == 'x') && point.board[x2][y2] == ' ') {
        printf("Никого нетю, чтобы рубить.\n");
        return 0;
      }
      if ((input[2] == '-') && point.board[x2][y2] != ' ') {
        printf("Стой, стой. Не занято ли там, а?\n");
        return 0;
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
  
  int x1 = (int)input[0] - 'A';
  int y1 = (int)input[1] - '1';
  int x2 = (int)input[3] - 'A';
  int y2 = (int)input[4] - '1';
  
  if ((x1 >= 0) && (x1 < 8) && (y1 >= 0) && (y1 < 8) && 
      (x2 >= 0) && (x2 < 8) && (y2 >= 0) && (y2 < 8)) {
    return 1;
  } else {
    printf("Дружочек, кажется вы вылезли за пределы доски, не?\n")
    return 0;
  }
  return 0;
}

int white_figure() {
  if ((point.board[x2][y2] > 'A') && (point.board[x2][y2] < 'S')) {
    printf("Упс, ведь там свои, не?\n");
    return 0;
  }
  switch (point.board[x1][y1]) {
    case 'P':
      if ((y1 == 1) && (point.board == ' ') && (y2 == 2 || y2 == 3) && (x1 == x2) && (input[2] == '-')) {
        return 1; //первый ход пешки
      } 
      if ((y2 - y1 == 1) && (x1 == x2) && (point.board[x2][y2] = ' ') && (input[2] == '-')) {
        return 1; 
      }
      if ((point.board[x2][y2] > 'a' && point.board[x2][y2] < 's') && 
          (x2 - x1 == 1 || x1 - x2 == 1) && (y2 - y1 == 1) && (input[2] == 'x')) {
        return 1;
      }
      break;
    case 'R':
      if ((x1 == x2) && (y1 > y2 || y1 < y2)) {
        return 1;
      }
      if ((y1 == y2) && (x1 > x2 || x1 < x2)) {
        return 1;
      }
      printf("Не, дружок, однако так ладья не ходит :(.\n")
      break;
    case 'N':
      if ((y1 - y2 == 1 || y2 - y1 == 1) && (x1 - x2 == 2 || x2 - x1 == 2)) {
        return 1;
      }
      if ((x1 - x2 == 1 || x2 - x1 == 1) && (y1 - y2 == 2 || y2 - y1 == 2)) {
        return 1;
      }
    case 'B':
      //чернополый слон
      if (((x1 % 2 == 1) && (y1 % 2 == 1)) || ((x1 % 2 == 0) && (y1 % 2 == 0))) {
        if (((x1 == 0 && y1 == 0) || (x1 == 7 && y1 == 7)) && (x2 == y2)) {
          return 1;
        } //движение по главной диагонали, при условии, что ход начинается из одного из углов
        if ((x2 + y2) == (x1 + y1) || (y2 - y1 == x2 - x1)) {
          return 1;
        } //остальные ходы
      }
      //белополый слон
      if (((x1 % 2 == 0) && (y1 % 2 == 1)) || ((x1 % 2 == 1) && (y1 % 2 == 0))) {
        if (((x1 == 0 && y1 == 7) || (x1 == 7 && y1 == 0)) && (x2 + y2 == 7)) {
            return 1; 
        } //движение по побочной диагонали, при условии, что ход начинается из одного из углов
        if ((x2 + y2 == x1 + x2) || (y2 - y1 == x2 - x1)) {
            return 1;
        } //остальные ходы
      }
  }
}

int black_figure() {


}















