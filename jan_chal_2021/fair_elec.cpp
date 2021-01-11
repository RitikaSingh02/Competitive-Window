#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{

    ll tests;
    cin >> tests;
    while (tests--)
    {
        ll s1, s2;
        cin >> s1 >> s2;
        vector<int> v1;
        vector<int> v2;
        for (int i = 0; i < s1; i++)
        {
            ll n;
            cin >> n;
            v1.push_back(n);
        }
        for (int i = 0; i < s2; i++)
        {
            ll n;
            cin >> n;
            v2.push_back(n);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end(), greater<int>());

        ll m = min(s1, s2);
        ll i = 0;
        bool c = false;
        ll d;
        ll swap = 0;
        while (i < m)
        {
            if (accumulate(v1.begin(), v1.end(), 0) > accumulate(v2.begin(), v2.end(), 0))
            {
                c = true;
                break;
            }
            else
            {
                d = v1[i];
                v1[i] = v2[i];
                v2[i] = d;
                swap++;
            }
            i++;
        }
        // cout<<accumulate(v1.begin(), v1.end(), 0);
        // cout<<accumulate(v2.begin(), v2.end(), 0);
        if (accumulate(v1.begin(), v1.end(), 0) > accumulate(v2.begin(), v2.end(), 0))
        {
            c = true;
            // break;
        }
        if (c == true)
        {
            cout << swap << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }

    return 0;
}
