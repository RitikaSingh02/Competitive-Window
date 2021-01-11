#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll tests;
    cin >> tests;
    while (tests--)
    {
        ll size;
        cin >> size;
        string s;

        cin >> s;
        // ll size= s.size();
        ll ele = size / 4;
        string sam[16];
        int j = 0;
        for (int i = 97; i < 97 + 16; i++)
        {
            string s(1, char(i));
            sam[j] = s;
            j++;
        }
        // for(auto i:sam)
        // {
        //     cout<<i;
        // }
        ll start = 0;
        //cout<<s;
        while (start < size)
        {
            //int st2=0,en2=16
            int st = 0, en = 16;
            ll end = start + 4;
            // ll j=0;
            // cout<<start<<" ";
            // cout<<end;
            for (ll i = start; i < end; i++)
            {
                // ll p=pow(2,j);
                if (s[i] == '0')
                {
                    // st=0;
                    en = (st + en) / 2;
                    // cout<<"y0";
                }
                if (s[i] == '1')
                {
                    st = (st + en) / 2;
                    // cout<<"y";
                    // en=8;
                }
                // st2=st;
                // en2=en;
            }
            // cout<<sam[en];
            // cout<<sam[st];
            //cout<<st <<" "<<en;
            cout << sam[(st + en) / 2];

            start += 4;
        }
        cout << "\n";
    }

    return 0;
}
