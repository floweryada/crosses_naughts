#ifndef N_C_5_H
#define N_C_5_H


const int n = 5;
void showBasicField();
void doMoves (int player, char basicField[n][n], char *player1, char *player2);
char fieldChecking(char basicField[n][n], int const n);
void gameResult(char res, char player1[20], char player2[20]);

#endif // N_C_5_H
