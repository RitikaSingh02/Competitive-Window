// https://www.codechef.com/APRIL21C/problems/SOCKS1
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    vector <int> v ;
    string c = "NO";
    for(int i=0 ; i< 3 ; i++)
        {
            int ele;
            cin>>ele;
            if(find(v.begin(),v.end(),ele) == v.end())
                v.push_back(ele);
            else
                c="YES";
            
        }
    cout<<c;
    
	// your code goes here
	return 0;
}
