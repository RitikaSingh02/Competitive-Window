//SPCTRIPS
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	// your code goes here
// 	3
// 3
// 4
// 5
// 3
// 6
// 9

    ll t;
    cin>>t;
    while(t--)
    {
        ll a , b , c=1 , n , ans=0;
        cin>>n;
        //solve the modulus taking a as Qb +c , take modulus both sides will get a%c =0
        //so a is a factor of c;
        //so initialise a as c and so b as c loop in and get the count
        for( ; c<=(n/2) ; c++)
        {
            for(b=c ; b<=n ; b+=c)
            {
                a=c;
                while(a<=n)
                {
                    if(a<b )
                    {
                        ans++;
                    }
                    else
                    {
                        if(a%b==c)
                            ans++;
                    }
                    a+=b;
                }
            }
            
        }
        cout<<ans<<"\n";
    }
	return 0;
}
