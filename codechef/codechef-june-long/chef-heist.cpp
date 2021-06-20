#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll D, d, P, Q;
        cin >> D >> d;
        cin >> P >> Q;
        ll n = D / d;
        ll rem = D % d;
        ll series_sum = Q * (n * (n - 1) / 2);
        ll res = (P * n + series_sum) * d;
        if (rem == 0)
        {

            cout << res << "\n";
        }
        else
        {
            // so in this case the days left will be (D%d) which was not
            //in the earlier sum result
            res += (rem) * (P + n * Q);
            cout << res << "\n";
        }
    }
    // your code goes here
    return 0;
}

// 3
// 4
// 13