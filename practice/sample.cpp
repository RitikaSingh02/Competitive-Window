#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll amt, n;
    vector<ll> v;
    cin >> amt >> n;
    for (ll i = 0; i < n; i++)
    {
        ll ele;
        cin >> ele;
        v.push_back(ele);
    }

    sort(v.begin(), v.end(), greater<ll>());
    ll num = amt;
    ll i = 0;
    ll sum = 0, count = 0, p = 0;
    // cout<<v[0]<<endl;
    while (num != 0 && i < n && sum != amt)
    {
        p = num / v[i];
        // cout<<num;
        sum += v[i] * p;
        num = amt - sum;
        count += p;
        i++;

        // cout<<p;
    }
    cout << count;
    return 0;
}
