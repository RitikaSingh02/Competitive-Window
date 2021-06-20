#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        // using binary search approach
        ll n, m;
        cin >> n >> m;
        vector<ll> A;
        vector<ll> B;
        vector<ll> T;
        vector<ll> O;

        A.push_back(-1);

        B.push_back(-1);
        for (ll i = 1; i <= n; i++)
        {
            ll ele;
            cin >> ele;
            if (ele != 0)
            {
                if (ele == 1)
                    O.push_back(i);
                else
                    T.push_back(i);
            }

            A.push_back(ele);
        }
        for (ll i = 1; i <= m; i++)
        {
            ll ele;
            cin >> ele;
            B.push_back(ele);
        }
        for (ll i = 1; i <= m; i++)
        {
            ll pos = B[i];
            if (A[pos] == 1 || A[pos] == 2 || pos == 1)
                cout << "0"
                     << " ";
            else
            {
                bool r = true;
                bool l = true;
                ll ans = INT_MAX;

                // binary search for the first ele greater than pos call it right
                auto right = upper_bound(T.begin(), T.end(), pos);
                // cout << right;
                if (T.size() != 0)
                {
                    if (right == T.end())
                    {
                        // cout << "ha bhai";
                        r = false;
                    }
                    else
                    {

                        ans = min(ans, *right - pos);
                    }
                }
                else
                {
                    r = false;
                }
                // bsearch for the first element in O that is less than pos
                auto left = lower_bound(O.begin(), O.end(), pos) - O.begin() - 1;

                // cout << "R" << *right << "L" << left;
                if (O.size() != 0)
                {
                    if (left == O.size() || left == -1)
                        l = false;
                    else
                    {
                        ans = min(ans, pos - O[left]);
                    }
                }
                else
                    l = false;
                // cout << r << " " << l;
                if (l == false && r == false)

                    cout << "-1"
                         << " ";
                else
                    cout << ans << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}