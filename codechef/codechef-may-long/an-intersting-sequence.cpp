#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll gcd_______ (ll a , ll b)
{
    if(a==b)
        return a;
    
    ll larger = (a>b)?a:b;
    ll smaller = (a<b)?a:b;
    ll rem = larger%smaller;
    ll g ;
    if(rem ==0)
        return smaller;
    while(rem !=0)
    {
        g = rem;
        rem = larger%smaller;
        larger=smaller;
        smaller = rem;
    }
    return g;
}
int main() {
    ll t ;
    cin>>t;
    while(t--)
    {
        ll k ;
        ll i =1;
        ll sum =0 ;
        cin>>k;
        for(ll j =1 ; j<=2*k ; j++)
        {
            // cout<<gcd(k + pow(i , 2) , k+ pow(i+1 , 2))<<"\n";
            sum+= gcd_______(k + pow(i , 2) , 2*i+1);
            i++;
        }
        cout<<sum<<"\n";
    }
	// your code goes here
	return 0;
}
