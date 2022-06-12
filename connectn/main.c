#include <stdio.h>
#include <stdbool.h>
#include "connectn.h"

int main(int argc, char* argv[]) {
    int numRows;
    int numCols;
    int piecesToWin;
    char** board;
    bool over = false;
    int player = 1;
    ReadArgs(argc, argv, &numRows, &numCols, &piecesToWin);
    board = CreateBoard(numRows, numCols);
    while (!over) {
        PrintBoard(board, numRows, numCols);
        PlayGame(board, numRows, numCols, &over, &player, piecesToWin);
        player++;
    }


    DeleteBoard(&board, numRows);

    return 0;
}