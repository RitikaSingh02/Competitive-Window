bool minSubsetSumDifference(vector<int>& arr, int n) {
    // Write your code here.
    int k = 0; // total  sum of the array
    for(int i =0 ; i < arr.size() ; i++) k+=arr[i];
    vector<vector<int>>dp(n , vector<int>(k + 1 , false));
    
//     return fun(n-1 , k , arr , dp);
    
    for(int i = 0 ; i< n ; i++)
        dp[i][0] = false;
    
    if(arr[0] <= k ) dp[0][arr[0]] = true;
    
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1; j <= k ; j++)
        {
            bool not_take = dp[i-1][j];
            bool take = false;
            if(arr[i] <= j)
            {
                take = dp[i-1][j - arr[i]];
            }
            dp[i][j] = take | not_take;
            
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
