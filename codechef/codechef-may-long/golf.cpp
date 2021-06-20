#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, h, k;
        // cal the forward vec
        cin >> n >> h >> k;
        if (h % k == 0 || (n + 1 - h) % k == 0) //check for middle eleement if its a factor of k then yes
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    // your code goes here
    return 0;
}
