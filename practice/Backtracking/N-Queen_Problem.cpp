#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isSAfe(int board[][10], int i, int j, int rows)
{
    //for checking if the queen is already there in the col
    for (int row = 0; row < i; row++)
    {
        if (board[row][j] == 1)
            return false;
    }

    //for diagonal

    int x = i;
    int y = j;

    //left diag
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
            return false;
        x--;
        y--;
    }

    x = i;
    y = j;

    //right diag
    while (x >= 0 && y < rows)
    {
        /* code */
        if (board[x][y] == 1)
            return false;
        x--;
        y++;
    }
    return true;
}
bool NQueen(int board[][10], int current_row, int rows)
{
    ///base case
    if (current_row == rows)
    {
        cout << "max rows reached\n";
        // print the board

        for (int k = 0; k < rows; k++)
        {
            for (int l = 0; l < rows; l++)
            {
                if (board[k][l] == 1)
                    cout << "Q ";
                else
                {
                    cout << "_ ";
                }
            }
            cout << "\n";
        }
        return true;
    }

    //recursive case

    for (int i = 0; i < rows; i++)
    {
        if (isSAfe(board, current_row, i, rows) == true)
        {
            board[current_row][i] = 1; //place the queen

            bool check = NQueen(board, current_row + 1, rows); //check if we could place the next queen after placing this queen
            //if not then we have to backtrack else continue;
            if (check)
            {
                return true;
            }
            else
            {
                //it means ki humko us position se queen hatani padegi
                board[current_row][i] = 0; //backtrck
            }
        }
    }

    return false;
}

int main()
{
    int n; //no of rows
    cin >> n;

    int board[10][10] = {0};

    NQueen(board, 0, n);

    return 0;
}