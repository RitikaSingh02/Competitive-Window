#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isprime(ll i)
{
    ll count = 0;
    for (ll j = 2; j <= (sqrt(i)); j++)
    {
        if (i % j == 0)
        {
            count++;
        }
    }
    if (count == 0)
        return true;

    return false;
}
int main()
{
    ll n, o, t;
    cin >> n;
    for (ll i = n;; i++)
    {
        if (isprime(i))
        {
            o = i;
            break;
        }
    }

    for (ll i = n;; i--)
    {
        if (isprime(i))
        {
            t = i;
            break;
        }
    }
    cout << o << t;
    if (abs(o - n) == abs(t - n))
        cout << max(o - n, t - n);
    else
        cout << min(o - n, t - n);

    return 0;
}
