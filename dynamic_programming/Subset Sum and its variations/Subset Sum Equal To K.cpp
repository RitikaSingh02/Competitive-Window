// https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0

//memoized code
bool fun(int curr_ind , int target , vector<int>arr , vector<vector<int>>&dp)
{
    if(target == 0) return true;
    if(curr_ind == 0) return (arr[0] == target);
    if(dp[curr_ind][target] != -1) return dp[curr_ind][target];
    bool not_take = fun(curr_ind - 1 , target , arr,dp);
    bool take = false;
    if(arr[curr_ind] <= target)
    take = fun(curr_ind -1 , target - arr[curr_ind] , arr,dp);
    return dp[curr_ind][target] = take || not_take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n , vector<int>(k + 1 , -1));
    
    return fun(n-1 , k , arr , dp);
}


// tabulated code:
bool fun(int curr_ind , int target , vector<int>arr , vector<vector<int>>&dp)
{
    if(target == 0) return true;
    if(curr_ind == 0) return (arr[0] == target);
    if(dp[curr_ind][target] != -1) return dp[curr_ind][target];
    bool not_take = fun(curr_ind - 1 , target , arr,dp);
    bool take = false;
    if(arr[curr_ind] <= target)
    take = fun(curr_ind -1 , target - arr[curr_ind] , arr,dp);
    return dp[curr_ind][target] = take || not_take;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>>dp(n , vector<int>(k + 1 , -1));
    
//     return fun(n-1 , k , arr , dp);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j <=k ; j++)
        {
            if(j == 0) dp[i][j] = 1;
            else
            if(i == 0) dp[i][j] = (arr[0] == j);
            else
            {
                bool not_take = dp[i-1][j];
                bool take = false;
                if(arr[i] <= j)
                {
                    take = dp[i-1][j - arr[i]];
                }
                dp[i][j] = take || not_take;
            }
        }
    }
    return dp[n-1][k];
}
