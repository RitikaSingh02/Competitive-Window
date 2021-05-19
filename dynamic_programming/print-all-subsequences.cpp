// naive
#include <bits/stdc++.h>
using namespace std;
#define ll long long


set <string> vec;

void fun(string s , string out , int n )
{
    if(n==0)
        {
            reverse(out.begin() , out.end());
            vec.insert(out);
            return;
        }
    // if we do not take the else
    fun(s , out , n-1);
    // if we take
    out+= s[n-1];
    fun(s , out , n-1);
}
int main()
{
    string s;
    cin>>s;
    fun(s , "" , s.size());
    for(auto i : vec)
        cout<<i<<" ";
    cout<<vec.size();
}

