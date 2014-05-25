#include "n_c_5.h"
#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;


void showBasicField()
{
    cout << "__" << "0-0" << "_" << "|" << "__" << "0-1" << "_" << "|" << "__" << "0-2" << "_" << "|" << "__" << "0-3" << "_" << "|" << "__" << "0-4" << "_" << endl;
    cout << "__" << "1-0" << "_" << "|" << "__" << "1-1" << "_" << "|" << "__" << "1-2" << "_" << "|" << "__" << "1-3" << "_" << "|" << "__" << "1-4" << "_" << endl;
    cout << "_" << "2-0" << "_" << "|" << "_" << "2-1" << "_" << "|" << "_" << "2-2" << "_" << "|" << "_" << "2-3" << "_" << "|" << "_" << "2-4" << "_" << endl;
    cout << "_" << "3-0" << "_" << "|" << "_" << "3-1" << "_" << "|" << "_" << "3-2" << "_" << "|" << "_" << "3-3" << "_" << "|" << "_" << "3-4" << "_" << endl;
    cout << "_" << "4-0" << "_" << "|" << "_" << "4-1" << "_" << "|" << "_" << "4-2" << "_" << "|" << "_" << "4-3" << "_" << "|" << "_" << "4-4" << "_" << "\n" << endl;
}

void doMoves (int player, char basicField[][n], char *player1, char *player2)
{
    if (player == 1) cout << player1 << ", ";
    else cout << player2 << ", ";
    cout << "make your move: ";

    int numCellX, numCellY;
    cout << "X: ";
    cin >> numCellX;
    cout << "Y: ";
    cin >> numCellY;
    cout << "\n";

    while ( (basicField[numCellX][numCellY] == 'O') || (basicField[numCellX][numCellY] == 'X') || ((numCellX || numCellY) > 4) || ((numCellX || numCellY) < 0) )
    {
        cout << "Enter the coordinates of cell (from 0 to 4) for your move. Don't forget about not empty cells: ";
        cout << "X: ";
        cin >> numCellX;
        cout << "Y: ";
        cin >> numCellY;
        cout << "\n";
    }

    if (player == 1) basicField[numCellX][numCellY] = 'X';
    else basicField[numCellX][numCellY] = 'O';
}

char fieldChecking(char basicField[][n], int const n)
{
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
                if (basicField[i][j] == basicField[i][j+1] && basicField[i][j+1] == basicField[i][j+2] && basicField[i][j+2] == basicField[i][j+3] && basicField[i][j+3] == basicField[i][j+4])
            return basicField[i][j];

                else if (basicField[j][i] == basicField[j+1][i] && basicField[j+1][i] == basicField[j+2][i] && basicField[j+2][i] == basicField[j+3][i] && basicField[j+3][i] == basicField[j+4][i])
            return basicField[j][i];

        else if (
                    ((basicField[i][i] == basicField[i+1][i+1] && basicField[i+1][i+1] == basicField[i+2][i+2] && basicField[i+2][i+2] == basicField[i+3][i+3] && basicField[i+3][i+3] == basicField[i+4][i+4])
                     || ( basicField[i][n-i] == basicField[i+1][n-(i+1)] && basicField[i+1][n-(i+1)] == basicField[i+2][n-(i+2)] && basicField[i+2][n-(i+2)] == basicField[i+3][n-(i+3)] && basicField[i+3][n-(i+3)] == basicField[i+4][n-(i+4)])) )
            return basicField[i][i];

        else return '--';
        }
    }
}

void gameResult(char res, char player1[20], char player2[20])
{
        if (res == 'X')
            cout << player1 << ", You're Winner! " << endl;
        else if (res == 'O')
            cout << player2 << ", You're Winner! " << endl;
        else
            cout << "Draw! Nobody is Winner :( " << endl;
}
