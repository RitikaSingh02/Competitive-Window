#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool count_subset(vector <ll> nums , int n , int sum)
{
    bool dp[n+1][sum+1];
    for(int i =0 ; i<=n ; i++ )
        dp[i][0] = true;// empty subset 
    for(int i =1 ; i<=sum ; i++ )
        dp[0][i] = false;// no subset will be obtained
    
        
    for(int i =0 ; i<=n ; i++)
    {
        for(int j =0 ; j <= sum ; j++)
        {
            if(nums[i]<=j)
            {
                dp[i][j] = dp[i-1][j] || dp[i][j - nums[i]];
            }
            else
                dp[i][j] = dp[i-1][j];
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
        nums.push_back(ele);
    }
    int n = nums.size();
    
    cout<<count_subset(nums , n , sum);

}
