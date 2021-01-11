#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ll test;
    cin >> test;
    while (test--)
    {
        ll arr[3];
        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }
        ll sec = arr[0];
        ll demand = arr[1];
        ll days = arr[2];
        ll sum = 0;
        for (int i = 0; i < sec; i++)
        {
            ll a;
            cin >> a;
            sum += a;
        }
        if (demand > sum)
        {
            cout << 0 << "\n";
        }
        else
        {

            if (sum >= demand * days)
            {
                cout << days << "\n";
            }
            else
            {
                cout << (long long)(sum / demand) << "\n";
            }
        }
    }
    return 0;
}
