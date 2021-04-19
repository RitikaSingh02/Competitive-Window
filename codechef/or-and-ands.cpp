#include <bits/stdc++.h>
#define ll long long
using namespace std;
//brute force
vector<vector<int>> make_subarray(ll *arr, vector<int> v, int n)
{
    vector<vector<int>> res;
    ll s = 0, e = 0;
    while (s < n)
    {
        if (e > n - 1)
        {

            s += 1;
            e = s;
            v.clear();
        }

        if (e < n)
        {
            v.push_back(arr[e]);
            res.push_back(v);
            // cout << res.size();
        }
        else
        {
            break;
        }

        e++;
    }

    return res;
}
void cal_or(vector<int> a)
{
    int ans = a[0];
    for (auto i : a)
    {
        ans |= i;
    }

    cout << ans << "\n";
}
int fun(int x, int y)
{
    return x & y;
}

void cal_and(ll *arr, int n)
{
    vector<vector<int>> res = make_subarray(arr, {}, n);
    vector<int> sub_and;
    for (auto i : res)
    {

        int ind = accumulate(i.begin(), i.end(), i[0], fun);

        sub_and.push_back(ind);
    }
    cal_or(sub_and);
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        ll arr[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int len = sizeof(arr) / sizeof(arr[0]);

        // cal_and(arr, len);
        // if (k == 1)
        //     cal_and(arr, len);
        // else
        cal_and(arr, len);

        for (ll i = 0; i < k; i++)
        {

            int p, q;
            cin >> p >> q;
            arr[p - 1] = q;
            // cout << "y";
            cal_and(arr, len);
        }

        // if (k == 1)
        // {
        //     int p, q;
        //     cin >> p >> q;
        //     arr[p - 1] = q;
        //     cal_and(arr, len);
        // }
    }

    return 0;
}
