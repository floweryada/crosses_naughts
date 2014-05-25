#include <iostream>
#include <cstring>
#include <windows.h>
#include "n_c_5.h"

using namespace std;


int main()
{
    char player1[20], player2[20];
    char res = '--';


    char basicField[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
    {
        basicField[i][j] = '-';
    }


    cout << "Enter the name of the first player: ";
    cin.getline (player1, 20);
    cout << "Enter the name of the second player: ";
    cin.getline (player2, 20);

    showBasicField();

    for (int moves = 1; moves <= n*n; moves++)
    {
        if (moves % 2) doMoves(1, basicField, player1, player2);
        else doMoves(2, basicField, player1, player2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "_" << basicField[i][j] << "_" << "|";
        }
        cout << endl;
    }

        if (moves >= (2*n-1) )
        {
            res = fieldChecking(basicField, n);
            if (res != '-')
                break;
        }
    }

    gameResult(res, player1, player2);

    return 0;
}

