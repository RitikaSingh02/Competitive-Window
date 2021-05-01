// https://www.codechef.com/APRIL21C/submit/SDICE
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ll n ;
    cin>>n;
    while(n--)
    {
        ll k,sum=0;
        cin>>k;
        
        ll remaind = k%4;
        sum = k/4;
        
        ll a =0,b=0,c=0,d=0,f=0;

        if(remaind ==1)
            d=1;
        if (remaind ==2)
            c=2 ;
        if(remaind ==3)
        {
            c=2 ;
            b =1;
        }
        
        if(sum >0)
        {
            a+=sum*4;
            f=(4-remaind)*4;
            
        }
        
        ll res = a*11 + b*15 + c*18 + d*20+f ;
        cout<< res <<"\n";


    }
	return 0;
}
