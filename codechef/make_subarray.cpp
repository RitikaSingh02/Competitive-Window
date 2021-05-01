#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
int main()
{
    ll arr[3] = {1, 2, 3};
    vector<vector<int>> res = make_subarray(arr, {}, 3);
    for (auto i : res)
    {

        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
