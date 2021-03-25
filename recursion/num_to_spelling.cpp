#include <bits/stdc++.h>
using namespace std;


//2048 two zero four eight
string val(int pos)
{
    string arr[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    return arr[pos];
}

void num_to_spl(int n)
{
    if (n==0)
        return ;
    else
    {
        int pos= n%10;
        n/=10;
        // p++;
        cout<<pos<<val(pos)<<" ";
        num_to_spl(n);
    }
    
}



int main()
{

    int n;
    cin>>n;
    num_to_spl(n);

    return 0;
}