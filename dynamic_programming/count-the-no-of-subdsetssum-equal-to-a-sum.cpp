#include<bits/stdc++.h>
#define ll long long
using namespace std;

int count_subset(vector <ll> nums , int n , int sum)
{
    int dp[n+1][sum+1];
    for(int i =0 ; i<=n ; i++ )
        dp[i][0] = 1;// empty subset 
    for(int i =1 ; i<=sum ; i++ )
        dp[0][i] = 0;// no subset will be obtained as size is zero
    
    // cout<<dp[6][0];
    for(int i =1 ; i<=n ; i++)
    {
        for(int j =1 ; j <= sum ; j++)
        {
            if(nums[i-1]<=j)
            {
                dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i-1]];
                
            }
            else
                dp[i][j] = dp[i-1][j];
            cout<<'{'<<i <<','<< j<<'}'<<" " <<dp[i][j]<<" " ;
        }
    }
    return dp[n][sum];
    
}


int main()
{
    vector <ll> nums;
    for(int i = 0 ; i < 6 ; i++)
    {
        ll ele ; 
        cin>>ele;
        // cout<<ele;
        nums.push_back(ele);
        
    }
    int n = nums.size();
    int sum = 10 ;
    
    cout<<"\n"<<"result= "<<count_subset(nums , n , sum);
}
