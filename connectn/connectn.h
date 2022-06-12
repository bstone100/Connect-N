#ifndef CONNECTN_H
#define CONNECTN_H

	void ReadArgs(int argc, char* argv[], int* numRows, int* numCols, int* piecesToWin);
    void PrintUsage();
    char** CreateBoard(int numRows, int numCols);
    void PrintBoard(char** board, int numRows, int numCols);
    void DeleteBoard(char*** board, int numRows);
    void PlayGame(char** board, int numRows, int numCols, bool* over, int* player, int piecesToWin);
    bool GameWon(char** board, int numRows, int numCols, int piecesToWin);
    bool RowWon(char** board, int numRows, int numCols, int piecesToWin);
    bool ColWon(char** board, int numRows, int numCols, int piecesToWin);
    bool LeftDiagWon(char** board, int numRows, int numCols, int piecesToWin);
    bool RightDiagWon(char** board, int numRows, int numCols, int piecesToWin);
    int ValidInput(char** board, int numRows, int numCols);
    bool OnlySpaces(char input[]);
    bool FullBoard(char** board, int numRows, int numCols);

#endif