#ifndef BOARD_H
#define BOARD_H

  void info();

  void input_data(int side); //side: 1 - белые, 2 - чёрные фигуры;

  int charTOint(char input[6]);

  void move_figure();

  int white_figure();

  int black_figure();

  int checkwin(int status);

  void pawn_transformation();

#endif //BOARD_H
