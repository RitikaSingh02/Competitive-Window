#include<bits/stdc++.h>
using namespace std;
#define ll long long

int knap(int wt[] , int val[] ,  int n , int cap)
{
    // base case // think of the smallest valid input
    if(n == 0 || cap ==0)
        return 0;
    /// code for choice started.
          // we will take the weight when its less than the capacity
          if(wt[n-1] <= cap)
          {
              // return the max between when you choose the element and when you do not
              return max(val[n-1] + knap(wt , val ,n-1,cap - wt[n-1]) ,knap(wt , val , n-1 , cap) );
          }
  
          else if(wt[n-1] > cap)
          {
              return knap(wt , val , n-1 , cap); // simply leave the element go n-1
          }
    // code for choice ended.
    
}
int main()
{
    int n , cap;
  // n : input len , cap : capacity of the knapsack
    cin>>n >>cap;
    int wt[n] , val[n];
    
    for(int i =0 ; i<n ; i++)
    {
        cin>>wt[i]>>val[i];
    }

    cout<<knap(wt , val , n , cap);
    
}
