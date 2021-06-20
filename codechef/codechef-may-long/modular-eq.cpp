#include <bits/stdc++.h>
#define ll long long
using namespace std;


void check(vector<ll>&arr , ll &c , ll n , ll m)
{
    for(ll i =2 ; i<=n ; i++)
        {
            ll a = i;
            ll lhs = m%a;
            c=c+arr[lhs];
                for(ll b =lhs ; b<=n ; b+=i)
                {
    
                    arr[b]+=1;
                    
                }
        }
}

int main() {
    ll t;
    cin>>t ;
    while(t--)
    {
        ll n , m , c=0;
        cin>>n>>m;
        std::vector<ll> arr(n+1 ,1) ;//initializing with 1 as when coz in that range there will be the cond true once
        
        check(arr , c , n ,m);

        cout<<c<<"\n";
    }
	// your code goes here
	return 0;
}
