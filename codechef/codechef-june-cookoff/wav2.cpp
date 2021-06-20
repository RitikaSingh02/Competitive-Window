#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> A;

    for (ll i = 0; i < n; i++)
    {
        ll ele;
        cin >> ele;
        A.push_back(ele);
    }
    sort(A.begin(), A.end());
    // ll i = 1;
    // ll ng = 0, p = 0;
    while (q--)
    {
        ll x;
        cin >> x;
        ll lb = lower_bound(A.begin(), A.end(), x) - A.begin();
        if (A[lb] == x)
        {
            cout << "0\n";
        }
        else
        {

            if ((n - lb) % 2 == 0)
            {
                cout << "POSITIVE\n";
            }
            else
            {
                cout << "NEGATIVE\n";
            }
        }

        // ng = 0;
        // p = 0;
        // i = 1;
    }

    return 0;
}