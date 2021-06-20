#include <bits/stdc++.h>
#define ll long long
using namespace std;

void res(ll x, ll y)
{
    ll res = x;
    res += y;
    cout << res << "\n";
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        ll A, B;
        cin >> a >> b;
        cin >> A >> B;
        res(A / a, B / b);
        // ll res = A/a ;
        // res+=B/b;
        // cout<<res<<"\n";
    }
    // your code goes here
    return 0;
}

// 13
// 13
// 11
