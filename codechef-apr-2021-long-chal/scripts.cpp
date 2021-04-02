https://www.codechef.com/APRIL21C/submit/SSCRIPT
#include <bits/stdc++.h>
#define ll long long;

using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--)
    {
        int  l , k;
        cin>> l >> k;
        string s;
        cin>>s;
        bool t = false;
        int counter =0;
        for( int i =0 ;i<l ; i++ )
        {
            if(s[i]=='*')
            {
                
                    counter++;
                    if(counter>=k )
                    {   
                        t = true;
                        break;
                    }
                
            }    
            else
                counter=0;
        }
        
        if(t==false)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
	// your code goes here
	return 0;
}
