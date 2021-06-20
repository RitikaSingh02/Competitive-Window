#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool b, c;
char arr[3][3];

void win(char a[][3])
{
    ll n = 2;
    char search = 'X';
    bool p;
    while (n--)
    {
        p = false;
        if (a[0][0] == search && a[0][1] == search && a[0][2] == search)
            p = true;
        if (a[1][0] == search && a[1][1] == search && a[1][2] == search)
            p = true;
        if (a[2][0] == search && a[2][1] == search && a[2][2] == search)
            p = true;
        if (a[0][0] == search && a[1][0] == search && a[2][0] == search)
            p = true;
        if (a[0][1] == search && a[1][1] == search && a[2][1] == search)
            p = true;
        if (a[0][2] == search && a[1][2] == search && a[2][2] == search)
            p = true;
        if (a[0][0] == search && a[1][1] == search && a[2][2] == search)
            p = true;
        if (a[0][2] == search && a[1][1] == search && a[2][0] == search)
            p = true;

        if(search == 'X')
            b=p;
        else
            c= p;
        search = 'O';
    }
};

void check(bool b, bool c, ll x, ll o, ll s)
{
    if (b == true && c == true || x < o || x - o > 1)
        cout << "3\n";
    else if (x == 0 && o == 0 && s == 9)
        cout << "2\n";
    else if (b && c == false && x > o)
        cout << "1\n";
    else if (b == false && c == true && x == o)
        cout << "1\n";
    else if (b == false && c == false && (s == 0))
        cout << "1\n";
    else if (b == false && c == false && (s > 0))
        cout << "2\n";
    else
        cout << "3\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        b = false, c = false;
        ll o = 0, x = 0, s = 0, sx = 0, so = 0;
        for (ll i = 0; i < 3; i++)
        {
            for (ll j = 0; j < 3; j++)
            {
                cin >> arr[i][j];
                // cout<<arr[i][j];
                if (arr[i][j] == '_')
                {
                    s++;
                }
                if (arr[i][j] == 'X')
                {
                    x++;
                    // sx += i;
                    // cout<<"x";
                }
                else if (arr[i][j] == 'O')
                {
                    o++;
                    // so += i;
                }
            }
        }
        win(arr);

        check(b, c, x, o, s);
    }

    // your code goes here
    return 0;
}
