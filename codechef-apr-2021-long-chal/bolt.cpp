//https://www.codechef.com/APRIL21C/submit/BOLT
#include <bits/stdc++.h>
#define ll long long
using namespace std;

float rounded(double x)
{
    
    float rounded = floor((x * 100) + .5) / 100;
    // cout<<rounded;
    return rounded;
}
int main() {
    int n ;
    cin>>n;
    while(n--)
    {
        double ele =1;
        for(int i =0; i<4;i++)
        {
            float el ;
            cin>>el;
            
            ele*=el;
        }
        // cout<<rounded(100/ele);
        if(rounded(100/ele) < float(9.58))//coz 9.58 is taken by default double here; typeid(9.58).name() == d
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }
	// your code goes here
	return 0;
}
