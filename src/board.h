#ifndef BOARD_H
#define BOARD_H

  void information();

  void input_data(int side); //side: 1 - белые, 2 - чёрные фигуры;

  int charTOint(char input[6], int side);

  void move_figure();

  int white_figure();

  int check_x();

  int check_y();

  int check_d(); //check side and main diagonals

  int black_figure();

  int checkwin(int status);

  void pawn_transformation();

#endif //BOARD_H
