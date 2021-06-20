#include <bits/stdc++.h>
#define ll long long
using namespace std;

void input(vector<pair<ll, ll>> &X, vector<pair<ll, ll>> &Y, multiset<ll> &x, multiset<ll> &y, ll n)
{
    // input
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        X.push_back({a, b});
        x.insert(a);
        Y.push_back({b, a});
        y.insert(b);
    }
}

void check(ll area)
{
    if (area != LONG_LONG_MAX) // this means there was not any change in the area
        cout << area << "\n";
    else
        cout << "0"
             << "\n";
}

void check1(ll area)
{
    if (area == LONG_LONG_MAX) // this means there was not any change in the area
        cout << "0"
             << "\n";
    else
        cout << area << "\n";
}

ll cal(vector<pair<ll, ll>> X, multiset<ll> y, ll i, ll h1, ll n)
{
    ll new_Area;
    ll h2 = abs(*(y.begin()) - *(y.rbegin()));
    new_Area = (X[i].first - X[0].first) * h1;
    new_Area = new_Area + (X[n - 1].first - X[i + 1].first) * h2;
    return new_Area;
}

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        vector<pair<ll, ll>> X, Y;
        multiset<ll> x, y;
        ll n;
        cin >> n;

        input(X, Y, x, y, n);
        // sort the vectors
        sort(Y.begin(), Y.end());

        sort(X.begin(), X.end());
        ll mx = LLONG_MIN, mi = LONG_LONG_MAX;
        // new_Area holds the min area
        ll new_Area = LONG_LONG_MAX;
        // ll h1 = 0, h2 = 0;
        for (ll i = 0; i < n - 1; i++)
        {
            mi = min(mi, X[i].second);

            mx = max(mx, X[i].second);
            ll h1 = mx - mi;
            auto find_it = y.find(X[i].second);
            // erase from the multi set as it is already in i t
            y.erase(find_it);

            ll h2 = abs(*(y.begin()) - *(y.rbegin()));
            ll newer_Area = (X[i].first - X[0].first) * h1;
            newer_Area = newer_Area + (X[n - 1].first - X[i + 1].first) * h2;
            if (newer_Area < new_Area)
                new_Area = newer_Area;
        }

        // reinitialize for the width part
        mx = LLONG_MIN;
        mi = LONG_LONG_MAX;
        // ll w1 = 0, w2 = 0;

        for (ll i = 0; i < n - 1; i++)
        {

            // for the width
            mi = min(mi, Y[i].second);
            mx = max(mx, Y[i].second);

            ll w1 = mx - mi;
            auto find_it_1 = x.find(Y[i].second);
            // erase from the multi set as it is already in i t
            x.erase(find_it_1);

            ll w2 = abs(*(x.begin()) - *(x.rbegin()));
            ll newer_Area = (Y[i].first - Y[0].first) * w1 + (Y[n - 1].first - Y[i + 1].first) * w2;
            if (newer_Area < new_Area)
                new_Area = newer_Area;
        }

        check(new_Area);
        X.clear();
        // Y.clear();
        x.clear();
        y.clear();
    }
    return 0;
}