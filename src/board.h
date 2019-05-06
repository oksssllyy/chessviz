#ifndef BOARD_H
#define BOARD_H

  void input_data(int side); //side: 1 - белые, 2 - чёрные фигуры;

  int charTOint();

  void move_figure();

  int white_figure();

  int black_figure();

  void log_steps();

  int checkwin();

  void pawn_transformation();

#endif //BOARD_H
