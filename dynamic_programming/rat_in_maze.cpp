#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool ratInMaze(char maze[10][10], int sol[][10], int i, int j, int m, int n)
{
    if (i > m || j > n)
    {
        cout << "rat is out of the maze";
        return false;
    }

    if (maze[i][j] == 'X')
    {
        return false;
    }
    if (i == m && j == n)
    {
        cout << "des reached\n";
        sol[m][n] = 1;
        //print the path that is followed
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }

    bool downsuccess = ratInMaze(maze, sol, i + 1, j, m, n);
    bool rightsuccess = ratInMaze(maze, sol, i, j + 1, m, n);

    //we need to undo the changes

    if (downsuccess || rightsuccess)
    {
        return true;
    }
    sol[i][j] = 0;

    return false;
}
int main()
{
    cout << "this is the rat maze prob";

    char maze[10][10] = {
        "OOOO",
        "OOXO",
        "OOOX",
        "0X00",
    };

    int sol[10][10] = {0};

    int m = 4, n = 4;

    ratInMaze(maze, sol, 0, 0, m - 1, n - 1);

    return 0;
}