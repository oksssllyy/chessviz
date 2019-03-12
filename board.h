#ifndef BOARD_H
#define BOARD_H

    struct Board
    {
	char board[8][8];
    };
    struct Board point;

    char letter[8] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    void mk_board();

#endif //BOARD_H
