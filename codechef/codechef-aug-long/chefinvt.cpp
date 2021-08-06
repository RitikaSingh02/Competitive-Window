//https://www.codechef.com/AUG21C/submit/CHFINVNT
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	//hashmap approach
// 	4
// 10 5 5
// 10 6 5
// 10 4 5
// 10 8 5
    ll t ;
    cin>>t;
    while(t--)
    {
        ll n , p , k;
        cin>>n>>p>>k;
        unordered_map<ll , vector<ll>>hash;
        ll f = p%k;
        for(ll i = 0 , j =0 ; i <k ; i++ , j = i%k)
        {
            if(j<=f)
            {
                ll g = i ;
                while(g<n)
                {
                   hash[j].push_back(g);
                   g+=k;
                }
                
            }
            else
                break;
        }
        ll m = p%k;
        ll ans=0;
        for(ll i = 0 ; i <m ; i++)
        {
            ans=ans +hash[i].size();
        }
        ll c =1 ;
        for(auto i : hash[m])
        {
            if(i==p)
                break;
            else
                c++;
        }
        cout<<ans+c<<"\n";
    }
	return 0;
}
