#include "board.h"
#include "board_print_plain.h"
#include <stdio.h>
#include <stdlib.h>

char input[6];
int x1, Y1, x2, y2;

void info(){
  printf("      Шахматы\n\n\n");
  printf("Обычный ход (пешка): A2-A3\nВзятие фигуры (пешкой): A4xB5\n\n");
  printf("Пример хода белых фигур:\nC2-C4 (Ходы белых фигур осуществляются вводом большых букв.)\nПример хода чёрных фигур:\nс7-с5 (Ходы чёрных фигур осуществляются вводом маленьких букв.\n\n");
  printf("Для вывода на экран данной информации введите в любой момент 'i'.\n");
}

void input_data(int side) {
  while (1) {
    while (1) {
      fgets(input, 6, stdin);
      if (input[0] == 'i') {
        info();
      }
      if ((input[2] != '-') && (input[2] != 'x')) {
        printf("Слушай, ошибочка вышла. Попробуй заново ввести: ");
      }
      if ((input[2] == 'x') && point.board[y2][x2] == ' ') {
        printf("Никого нетю, чтобы рубить.\n");
      }
      if ((input[2] == '-') && point.board[y2][x2] != ' ') {
        printf("Стой, стой. Не занято ли там, а?\n");
      }
      if (charTOint(input)){
        break;
      }
      printf("Произошла ошибочка. Попробуйте ввести заново ход, уважаемый шамхматист :)");
    }
    if (side == 1){
      if (white_figure()) {
        break;
      } else {
        printf("Произошла ошибочка. Попробуйте ввести заново ход, уважаемый шамхматист :)");
      }
    }
    if (side == 2){
      if (black_figure()) {
        break;
      } else {
        printf("Произошла ошибочка. Попробуйте ввести заново ход, уважаемый шамхматист :)");
      }
    } 
  }
}

int charTOint(char input[6]) {
  
  x1 = (int)input[0] - 'A';
  Y1 = (int)input[1] - '1';
  x2 = (int)input[3] - 'A';
  y2 = (int)input[4] - '1';
  
  if ((x1 >= 0) && (x1 < 8) && (Y1 >= 0) && (Y1 < 8) && 
      (x2 >= 0) && (x2 < 8) && (y2 >= 0) && (y2 < 8)) {
    return 1;
  } else {
    printf("Дружочек, кажется вы вылезли за пределы доски, не?\n");
    return 0;
  }
  return 0;
}

int white_figure() {
  if ((point.board[y2][x2] > 'A') && (point.board[y2][x2] < 'S')) {
    printf("Упс, ведь там свои, не?\n");
    return 0;
  }
  switch (point.board[Y1][x1]) {
    case 'P':
      if ((Y1 == 1) && (point.board[y2][x2] == ' ') && (y2 == 2 || y2 == 3) && (x1 == x2) && (input[2] == '-')) {
        return 1; //первый ход пешки
      } 
      if ((y2 - Y1 == 1) && (x1 == x2) && (point.board[y2][x2] = ' ') && (input[2] == '-')) {
        pawn_transformation();
        return 1; 
      }
      if ((point.board[y2][x2] > 'a' && point.board[y2][x2] < 's') && 
          (x2 - x1 == 1 || x1 - x2 == 1) && (y2 - Y1 == 1) && (input[2] == 'x')) {
        pawn_transformation();
        return 1;
      }
      break;
    case 'R':
      if ((x1 == x2) && (Y1 > y2 || Y1 < y2)) {
        return 1;
      }
      if ((Y1 == y2) && (x1 > x2 || x1 < x2)) {
        return 1;
      }
      printf("Не, дружок, однако так ладья не ходит :(.\n");
      break;
    case 'N':
      if ((Y1 - y2 == 1 || y2 - Y1 == 1) && (x1 - x2 == 2 || x2 - x1 == 2)) {
        return 1;
      }
      if ((x1 - x2 == 1 || x2 - x1 == 1) && (Y1 - y2 == 2 || y2 - Y1 == 2)) {
        return 1;
      }
      break;
    case 'B':
      //чернополый слон
      if (((x1 % 2 == 1) && (Y1 % 2 == 1)) || ((x1 % 2 == 0) && (Y1 % 2 == 0))) {
        if (((x1 == 0 && Y1 == 0) || (x1 == 7 && Y1 == 7)) && (x2 == y2)) {
          return 1;
        } //движение по главной диагонали, при условии, что ход начинается из одного из углов
        if ((x2 + y2) == (x1 + Y1) || (y2 - Y1 == x2 - x1)) {
          return 1;
        } //остальные ходы
      }
      //белополый слон
      if (((x1 % 2 == 0) && (Y1 % 2 == 1)) || ((x1 % 2 == 1) && (Y1 % 2 == 0))) {
        if (((x1 == 0 && Y1 == 7) || (x1 == 7 && Y1 == 0)) && (x2 + y2 == 7)) {
            return 1; 
        } //движение по побочной диагонали, при условии, что ход начинается из одного из углов
        if ((x2 + y2 == x1 + Y1) || (y2 - Y1 == x2 - x1)) {
            return 1;
        } //остальные ходы
      }
      break;
    case 'Q':
      if (Y1 == y2) {
        if (x2 > x1) { 
          for (int i = x1; i < x2; i++) {
            if (point.board[y2][i] != ' ') {
              printf("По пути есть фигура. Нельзя дойти до назначенного места.\n");
              return 0;
            }
          }
        return 1;
        }
        if (x2 < x1) {
          for (int i = x1; i > x2; i--) {
            if (point.board[y2][i] != ' ') {
              printf("По пути есть фигура. Нельзя дойти до назначенного места.\n");
              return 0;
            }  
          }
        return 1;
        }
      } //движение фигуры по горизонтали
      if (x1 == x2) {
        if (y2 > Y1) { 
          for (int i = Y1; i < y2; i++) {
            if (point.board[i][x2] != ' ') {
              printf("По пути есть фигура. Нельзя дойти до назначенного места.\n");
              return 0;
            }
          }
        return 1;
        }
        if (y2 < Y1) {
          for (int i = Y1; i > y2; i--) {
            if (point.board[i][x2] != ' ') {
              printf("По пути есть фигура. Нельзя дойти до назначенного места.\n");
              return 0;
            }  
          }
        return 1;
        }
      } //движение фигуры по вертикали
      if (x2 + y2 == x1 + Y1) {
        if (x2 < x1) {
          for (int i = x1; i > x2; i--) {
            for (int j = Y1; j < y2; j++) {
              if (point.board[j][i] != ' ') {
                printf("По пути есть фигура.\n");
                return 0;
              }
            }
          }
          return 1;
        }
        if (x2 > x1) {
          for (int i = x1; i < x2; i++) {
            for (int j = Y1; j > y2; j--) {
              if (point.board[j][i] != ' ') {
                printf("По пути есть фигура.\n");
                return 0;
              }
            }
          }
          return 1;
        }  
      } //движение типа по побочным диагоналям
      if (y2 - Y1 == x2 - x1) {
        if (x2 > x1) {
          for (int i = x1; i < x2; i++) {
            for (int j = Y1; j < y2; j++) {
              if (point.board[j][i] != ' ') {
                printf("По пути есть фигура.\n");
                return 0;
              }
            }
          }
        }
        if (x2 < x1) {
          for (int i = x1; i > x2; i--) {
            for (int j = Y1; j > y2; j--) {
              if (point.board[j][i] != ' ') {
                printf("По пути есть фигура.\n");
                return 0;
              }
            }
          }
        }
      } //движение фигуры типа по главным диагоналям
      break;
    case 'K':
      if (((x1 - x2 != 1) && (Y1 - y2 != 1)) || ((x2 - x1 != 1) && (y2 - Y1 != 1))) {
        return 0;
      }
      if (y2 == Y1) {
        if ((x2 - x1 == 1) || (x1 - x2 == 1)) {
          return 1;
        }
      }
      if (x2 == x1) {
        if ((y2 - Y1 == 1) || (Y1 - y2 == 1)) {
          return 1;
        }
      }
      if (x2 - x1 == 1) {
        if ((y2 - Y1 == 1) || (Y1 - y2 == 1)) {
          return 1;
        }
      }
      if (x1 - x2 == 1) {
        if ((y2 - Y1 == 1) || (Y1 - y2 == 1)) {
          return 1;
        }
        break;
      }
  }
  return 0;
}

int black_figure() {
  if ((point.board[y2][x2] > 'a') && (point.board[y2][x2] < 's')) {
    printf("Упс, ведь там свои, не?\n");
    return 0;
  }
  switch (point.board[x1][Y1]) {
    case 'p':
      if ((Y1 == 6) && (point.board[y2][x2] == ' ') && (y2 == 5 || y2 == 4) && (x1 == x2) && (input[2] == '-')) {
        return 1; //первый ход пешки
      } 
      if ((y2 - Y1 == 1) && (x1 == x2) && (point.board[y2][x2] = ' ') && (input[2] == '-')) {
        pawn_transformation();
        return 1; 
      }
      if ((point.board[y2][x2] > 'A' && point.board[y2][x2] < 'S') && 
          (x2 - x1 == 1 || x1 - x2 == 1) && (Y1 - y2 == 1) && (input[2] == 'x')) {
        pawn_transformation();
        return 1;
      }
      break;
    case 'r':
      if ((x1 == x2) && (Y1 > y2 || Y1 < y2)) {
        return 1;
      }
      if ((Y1 == y2) && (x1 > x2 || x1 < x2)) {
        return 1;
      }
      printf("Не, дружок, однако так ладья не ходит :(.\n");
      break;
    case 'n':
      if ((Y1 - y2 == 1 || y2 - Y1 == 1) && (x1 - x2 == 2 || x2 - x1 == 2)) {
        return 1;
      }
      if ((x1 - x2 == 1 || x2 - x1 == 1) && (Y1 - y2 == 2 || y2 - Y1 == 2)) {
        return 1;
      }
      break;
    case 'b':
      //чернополый слон
      if (((x1 % 2 == 1) && (Y1 % 2 == 1)) || ((x1 % 2 == 0) && (Y1 % 2 == 0))) {
        if (((x1 == 0 && Y1 == 0) || (x1 == 7 && Y1 == 7)) && (x2 == y2)) {
          return 1;
        } //движение по главной диагонали, при условии, что ход начинается из одного из углов
        if ((x2 + y2) == (x1 + Y1) || (y2 - Y1 == x2 - x1)) {
          return 1;
        } //остальные ходы
      }
      //белополый слон
      if (((x1 % 2 == 0) && (Y1 % 2 == 1)) || ((x1 % 2 == 1) && (Y1 % 2 == 0))) {
        if (((x1 == 0 && Y1 == 7) || (x1 == 7 && Y1 == 0)) && (x2 + y2 == 7)) {
            return 1; 
        } //движение по побочной диагонали, при условии, что ход начинается из одного из углов
        if ((x2 + y2 == x1 + Y1) || (y2 - Y1 == x2 - x1)) {
            return 1;
        } //остальные ходы
      }
      break;
    case 'q':
      if (Y1 == y2) {
        if (x2 > x1) { 
          for (int i = x1; i < x2; i++) {
            if (point.board[y2][i] != ' ') {
              printf("По пути есть фигура. Нельзя дойти до назначенного места.\n");
              return 0;
            }
          }
        return 1;
        }
        if (x2 < x1) {
          for (int i = x1; i > x2; i--) {
            if (point.board[y2][i] != ' ') {
              printf("По пути есть фигура. Нельзя дойти до назначенного места.\n");
              return 0;
            }  
          }
        return 1;
        }
      } //движение фигуры по горизонтали
      if (x1 == x2) {
        if (y2 > Y1) { 
          for (int i = Y1; i < y2; i++) {
            if (point.board[i][x2] != ' ') {
              printf("По пути есть фигура. Нельзя дойти до назначенного места.\n");
              return 0;
            }
          }
        return 1;
        }
        if (y2 < Y1) {
          for (int i = Y1; i > y2; i--) {
            if (point.board[i][x2] != ' ') {
              printf("По пути есть фигура. Нельзя дойти до назначенного места.\n");
              return 0;
            }  
          }
        return 1;
        }
      } //движение фигуры по вертикали
      if (x2 + y2 == x1 + Y1) {
        if (x2 < x1) {
          for (int i = x1; i > x2; i--) {
            for (int j = Y1; j < y2; j++) {
              if (point.board[j][i] != ' ') {
                printf("По пути есть фигура.\n");
                return 0;
              }
            }
          }
          return 1;
        }
        if (x2 > x1) {
          for (int i = x1; i < x2; i++) {
            for (int j = Y1; j > y2; j--) {
              if (point.board[j][i] != ' ') {
                printf("По пути есть фигура.\n");
                return 0;
              }
            }
          }
          return 1;
        }  
      } //движение типа по побочным диагоналям
      if (y2 - Y1 == x2 - x1) {
        if (x2 > x1) {
          for (int i = x1; i < x2; i++) {
            for (int j = Y1; j < y2; j++) {
              if (point.board[j][i] != ' ') {
                printf("По пути есть фигура.\n");
                return 0;
              }
            }
          }
        }
        if (x2 < x1) {
          for (int i = x1; i > x2; i--) {
            for (int j = Y1; j > y2; j--) {
              if (point.board[j][i] != ' ') {
                printf("По пути есть фигура.\n");
                return 0;
              }
            }
          }
        }
      } //движение фигуры типа по главным диагоналям
      break;
    case 'k':
      if (((x1 - x2 != 1) && (Y1 - y2 != 1)) || ((x2 - x1 != 1) && (y2 - Y1 != 1))) {
        return 0;
      }
      if (y2 == Y1) {
        if ((x2 - x1 == 1) || (x1 - x2 == 1)) {
          return 1;
        }
      }
      if (x2 == x1) {
        if ((y2 - Y1 == 1) || (Y1 - y2 == 1)) {
          return 1;
        }
      }
      if (x2 - x1 == 1) {
        if ((y2 - Y1 == 1) || (Y1 - y2 == 1)) {
          return 1;
        }
      }
      if (x1 - x2 == 1) {
        if ((y2 - Y1 == 1) || (Y1 - y2 == 1)) {
          return 1;
        }
      }
      break;
  }
  return 0;
}

void pawn_transformation() {
  char change_pawn;
  if ((point.board[Y1][x1] == 'p') && (y2 == 0)) {
    while (1) {
      printf("Введите в какую фигуру желаете превратить:");
      change_pawn = getchar();
      if ((change_pawn == 'r') || (change_pawn == 'n') || (change_pawn == 'b') ||
          (change_pawn == 'q')) {
        point.board[Y1][x1] = change_pawn;
        break;
      } else {
        printf("Введите правильную фигуру.\n");
      }
    }
  }
  if ((point.board[Y1][x1] == 'P') && (y2 == 7)) {
    while (1) {
      printf("Введите в какую фигуру желаете превратить:");
      change_pawn = getchar();
      if ((change_pawn == 'R') || (change_pawn == 'N') || (change_pawn == 'B') ||
          (change_pawn == 'Q')) {
        point.board[Y1][x1] = change_pawn;
        break;
      } else {
        printf("Введите правильную фигуру.\n");
      }
    }
  }
}

void move_figure() {
  point.board[y2][x2] = point.board[Y1][x1];
  point.board[Y1][x1] = ' ';
}

int checkwin(int status) {
  int player = 0;
  if (status == 1) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (point.board[j][i] == 'q') {
          player = 1;
        }
      }
    }
  }
  if (status == 2) {
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (point.board[j][i] == 'Q') {
          player = 2;
        }
      }
    }
  }

  if (player == 0) {
    return status;
  }
}














