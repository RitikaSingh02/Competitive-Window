#include <bits/stdc++.h>
using namespace std;

int climbing_stairs(int n)
{
    //basecase
    if (n % 2 == 0)
        return 2;
    else
    {
        return 1 + climbing_stairs(n - 1);
    }
}

int main()
{
    int n;
    cin >> n;
    cout << climbing_stairs(n);
    return 0;
}