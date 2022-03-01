int minSubsetSumDifference(vector<int>& arr, int n)
{
    int k =0;
    for(int i = 0 ; i < n ;i++) k+=arr[i];
    vector<vector<bool>> dp(n , vector<bool>(k + 1 , false));
    for(int i = 0 ; i < n ; i++)dp[i][0] = true;
    if(arr[0] <=k) dp[0][arr[0]] = true;
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <=k ; j++)
        {
            int not_take = dp[i-1][j];
            int take = 0;
            if(arr[i] <= j)
            {
                take = dp[i-1][j - arr[i]];
            }
            dp[i][j] = take || not_take;
        }
        
    }

    // dp[n-1][col -> 0 .. k] will tell the ans
    int mini = 1e9;
    for(int s1 = 0 ; s1 <=k/2 ; s1++ )
    {
        if(dp[n-1][s1] == true)
            mini = min(mini , abs((k - s1) - s1));
    }
//     cout<<mini<<" ";
    
    return mini;

    
}
