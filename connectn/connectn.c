#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "connectn.h"

void ReadArgs(int argc, char* argv[], int* numRows, int* numCols, int* piecesToWin) {
    if (argc < 4) {
        printf("Not enough arguments entered\n");
        PrintUsage();
        exit(0);
    } else if (argc > 4) {
        printf("Too many arguments entered\n");
        PrintUsage();
        exit(0);
    }
    *numRows = atoi(argv[1]);
    *numCols = atoi(argv[2]);
    *piecesToWin = atoi(argv[3]);
}
char** CreateBoard(int numRows, int numCols) {
    char** board;
    board = (char**)malloc(sizeof(char*) * numRows);
    for (int i = 0; i < numRows; i++) {
        board[i] = (char*)malloc(sizeof(char) * numCols);
    }
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            board[row][col] = ' ';
        }
    }
    return board;
}
void PrintBoard(char** board, int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) {
        int side = numRows - row - 1;
        printf("%d ", side);
        for (int col = 0; col < numCols; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
    printf("  ");
    for (int i = 0; i < numCols; i++) {
        printf("%d ", i);
    }
    printf("\n");
}
void PlayGame(char** board, int numRows, int numCols, bool* over, int* player, int piecesToWin) {
    if (GameWon(board, numRows, numCols, piecesToWin)) {
        *over = true;
        return;
    }
    if (FullBoard(board, numRows, numCols)) {
        *over = true;
        printf("Tie game!\n");
        return;
    }
    int input = ValidInput(board, numRows, numCols);
    for (int row = numRows - 1; row >= 0; row--) {
        if (board[row][input] == ' ') {
            if (*player % 2 != 0) {
                board[row][input] = 'X';
            } else if (*player % 2 == 0) {
                board[row][input] = 'O';
            }
            break;
        }
    }

}
bool FullBoard(char** board, int numRows, int numCols) {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}
bool GameWon(char** board, int numRows, int numCols, int piecesToWin) {
    bool rowWon = RowWon(board, numRows, numCols, piecesToWin);
    bool colWon = ColWon(board, numRows, numCols, piecesToWin);
    bool leftDiagWon = LeftDiagWon(board, numRows, numCols, piecesToWin);
    bool rightDiagWon = RightDiagWon(board, numRows, numCols, piecesToWin);
    if (rowWon || colWon || leftDiagWon || rightDiagWon) {
        return true;
    }
    return false;
}
bool RowWon(char** board, int numRows, int numCols, int piecesToWin) {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col <= numCols - piecesToWin; col++) {
            bool test = false;
            for (int i = col; i < col + piecesToWin; i++) {
                if (board[row][i] == 'X') {
                    test = true;
                } else {
                    test = false;
                    break;
                }
            }
            if (test) {
                printf("Player 1 Won!\n");
                return true;
            }
        }
    }
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col <= numCols - piecesToWin; col++) {
            bool test = false;
            for (int i = col; i < col + piecesToWin; i++) {
                if (board[row][i] == 'O') {
                    test = true;
                } else {
                    test = false;
                    break;
                }
            }
            if (test) {
                printf("Player 2 Won!\n");
                return true;
            }
        }
    }

    return false;
}
bool ColWon(char** board, int numRows, int numCols, int piecesToWin) {
    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row <= numRows - piecesToWin; row++) {
            bool test = false;
            for (int i = row; i < row + piecesToWin; i++) {
                if (board[i][col] == 'X') {
                    test = true;
                } else {
                    test = false;
                    break;
                }
            }
            if (test) {
                printf("Player 1 Won!\n");
                return true;
            }
        }
    }
    for (int col = 0; col < numCols; col++) {
        for (int row = 0; row <= numRows - piecesToWin; row++) {
            bool test = false;
            for (int i = row; i < row + piecesToWin; i++) {
                if (board[i][col] == 'O') {
                    test = true;
                } else {
                    test = false;
                    break;
                }
            }
            if (test) {
                printf("Player 2 Won!\n");
                return true;
            }
        }
    }
    
    return false;
}
bool LeftDiagWon(char** board, int numRows, int numCols, int piecesToWin) {
    for (int row = 0; row <= numRows - piecesToWin; row++) {
        for (int col = 0; col <= numCols - piecesToWin; col++) {
            bool test = false;
            for (int i = row, j = col; i < row + piecesToWin; i++, j++) {
                if (board[i][j] == 'X') {
                    test = true;
                } else {
                    test = false;
                    break;
                }
            }
            if (test) {
                printf("Player 1 Won!\n");
                return true;
            }
        }
    }
    for (int row = 0; row <= numRows - piecesToWin; row++) {
        for (int col = 0; col <= numCols - piecesToWin; col++) {
            bool test = false;
            for (int i = row, j = col; i < row + piecesToWin; i++, j++) {
                if (board[i][j] == 'O') {
                    test = true;
                } else {
                    test = false;
                    break;
                }
            }
            if (test) {
                printf("Player 2 Won!\n");
                return true;
            }
        }
    }
    
    return false;
}
bool RightDiagWon(char** board, int numRows, int numCols, int piecesToWin) {
    for (int row = numRows - 1; row > numRows - piecesToWin; row--) {
        for (int col = 0; col <= numCols - piecesToWin; col++) {
            bool test = false;
            for (int i = row, j = col; i > row - piecesToWin; i--, j++) {
                if (board[i][j] == 'X') {
                    test = true;
                } else {
                    test = false;
                    break;
                }
            }
            if (test) {
                printf("Player 1 Won!\n");
                return true;
            }
        }
    }
    for (int row = numRows - 1; row > numRows - piecesToWin; row--) {
        for (int col = 0; col <= numCols - piecesToWin; col++) {
            bool test = false;
            for (int i = row, j = col; i > row - piecesToWin; i--, j++) {
                if (board[i][j] == 'O') {
                    test = true;
                } else {
                    test = false;
                    break;
                }
            }
            if (test) {
                printf("Player 2 Won!\n");
                return true;
            }
        }
    }
    
    return false;
}


int ValidInput(char** board, int numRows, int numCols) {
    int test = 0;
    double final = 0;
    char extra[1000] = "";
    while (test != 1) {
        printf("Enter a column between 0 and %d to play in: ", numCols - 1);
        test = scanf("%lf", &final);
        scanf("%[^\n]", extra);
        if (test != 0) { // if test is succesful
            if (final < 0 || final > numCols - 1) { // out of range fails
                test = 0;
            } else if (final - (int)final != 0) { // decimal fails
                test = 0;
            } else if (OnlySpaces(extra) == 1) { // spaces after passes
                test = 1;
            } else if (strlen(extra) > 0) { // chars after fails
                if (isprint(extra[0])) {
                    test = 0;
                } else {
                    test = 1;
                }
            }
        } else { // if test is unsuccesful
            test = 0;
        }
        extra[0] = '\0'; // clear extra
        if (test == 1) {
            for (int row = 0; row < numRows; row++) {
                if (board[row][(int)final] == ' ') {
                    test = 1;
                    break;
                } else {
                    test = 0;
                }
            }
        }
    }
    return (int)final;
}
bool OnlySpaces(char input[]) {
    bool onlySpaces = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isspace(input[i])) {
            onlySpaces = true;
        } else {
            onlySpaces = false;
            break;
        }
    }
    return onlySpaces;
}
void DeleteBoard(char*** board, int numRows) {
    for (int row = 0; row < numRows; row++) {
        free((*board)[row]);
    }
    free(*board);
    *board = NULL;
}
void PrintUsage() {
    printf("Usage: connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
}