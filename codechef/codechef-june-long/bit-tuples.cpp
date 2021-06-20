#include <bits/stdc++.h>
#define ll long long
#define modu 1000000007
using namespace std;

void check(ll &y, ll &x, ll &out, ll p)
{
    if (y & 1) //if its odd
        out = (out * x) % p;

    y = y >> 1; //right shif the val;
    x = (x * x) % p;
}

ll mod_exponentiation___(ll x, ll y, ll p)
{

    x = (x % p);
    ll out = 1;
    if (x == 0) // as 0 should not be raised to a power
        return 0;

    while (y > 0) //check
    {
        check(y, x, out, p);
    }
    return out;
}

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        ll ans;
        // first obs is that if 0 is there then the ans is obtainned
        // conting all the cases with zero
        // ans += (n - 1) * (pow(2, m - 1));
        // ans = mod_exponentiation___(2, n - 1, modu);
        ans = mod_exponentiation___(2, n, modu);
        ans -= 1;
        ans = ans % modu;
        ans = mod_exponentiation___(ans, m, modu);

        cout << ans << "\n";

        // thinking of starting with 1
        // what we want min of one even no to get the and to be zero

        // if we get a minimum of 2 even num the ans is yes
    }
    return 0;
}