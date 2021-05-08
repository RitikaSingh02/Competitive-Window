#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define r 1000000007
ll mod_exponentiation(ll x, ll y, ll p)
{
    ll out = 1;
    x = x % p; 
  
    if (x == 0) return 0; 
     
 
    while (y > 0)
    {
        if (y & 1)
            out = (out*x) % p;

        y = y>>1;
        x = (x*x) % p;
    }
    return out;
}
 
int main() {
    ll t;
    cin>>t;
    while(t--)
    {
        ll n ;
        cin>>n;
         
        // cout<<res;
        // now to generate the res we have to do % 10^9 +7
        // res = res%(pow(10,9) +7);// we cant do this range prb
        
        // apply modular exponentiation
        
        cout<<mod_exponentiation(2, n-1 , r )<<"\n";
        
    }
	// your code goes here
	return 0;
}
