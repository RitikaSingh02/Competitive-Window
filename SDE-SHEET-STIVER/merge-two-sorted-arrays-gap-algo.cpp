#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    vector<ll>b{1 ,2 , 90 , 10};
    vector<ll>a{6 , 8 , 7};
    //1 ,2 , 6, 7 , 8 , 9 , 10
    int gap = ceil((a.size() + b.size())/2);
    while(gap>=1)
    {
        int i , j;
        for(i = 0 ; i+gap <a.size() ; i++)
        {
            if(a[i] > a[i+gap])
                swap(a[i+gap] , a[i]);
        }
        j = (gap > a.size()?gap-a.size():0);
        for(;i < a.size() && j < b.size(); i++ , j++)
        {
                 if (a[i] > b[j])
                    swap(a[i], b[j]);
        }
        
         if (j < b.size()) {
            // comparing elements in the second array.
            for (j = 0; j + gap < b.size(); j++)
                if (b[j] > b[j + gap])
                    swap(b[j], b[j + gap]);
        }
        gap=ceil(gap/2);
    }
    for(auto i : a)
        cout<<i<<" ";
    for(auto j : b)
        cout<<j<<" ";
    
    return 0 ;
}
