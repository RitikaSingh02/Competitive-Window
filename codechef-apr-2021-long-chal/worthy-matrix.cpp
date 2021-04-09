#include <bits/stdc++.h>
using namespace std;
//TLE CODE!!
int main()
{
    // your code goes here

    int t;
    cin >> t;
    while (t--)
    {
        int k = 2;
        int r, c, K;
        int counter = 0;

        vector<vector<int>> mat;

        cin >> r >> c >> K;
        for (int i = 0; i < r; i++)
        {
            vector<int> subs;
            for (int j = 0; j < c; j++)
            {
                // cin >> mat[i][j];
                int ele;
                cin >> ele;
                subs.push_back(ele);

                if (ele >= K)
                    counter++;
            }
            mat.push_back(subs);
        }
        // cout << "\n";
        bool cond = false;
        while (k < min(r, c))
        {
            for (int i = 0; i < r - k + 1; i++)
            {
                // column of first cell in current sub-square of size k x k
                for (int j = 0; j < c - k + 1; j++)
                {
                    // Calculate and print sum of current sub-square
                    int sum = 0;
                    for (int p = i; p < k + i; p++)
                    {
                        for (int q = j; q < k + j; q++)
                        {
                            cout << mat[p][q] << " ";
                            sum += mat[p][q];
                            int avg = sum / (k * k);
                            if (avg >= K)
                                break;
                        }
                        // cout << "\n";
                    }
                    int avg = sum / (k * k);
                    if (avg >= K)
                    {
                        // cout << "\ncond" << counter;
                        counter += (r - i);
                        bool cond = true;
                        break; // all matrices formed right will have greater mean
                    }
                    if (cond == true)
                        break; // all matrices formed below will have greater mean
                }
            }
            k++;
        }

        // cout << "counter" << counter;
        cout << counter << "\n";
    }
    return 0;
}
