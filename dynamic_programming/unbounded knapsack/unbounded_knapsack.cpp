//memoization
int fun(int curr , int w , vector<int>pr , vector<int>wt , vector<vector<int>>&dp)
{
//     if(w == 0) return 0;
    if( curr == 0 )
    {
        int rem = w/wt[0];
        return pr[0] * rem;
    }
    if(dp[curr][w]!=-1) return dp[curr][w];
    int not_take = 0 + fun(curr - 1 , w , pr , wt ,dp);
    int take = 0;
    if(wt[curr] <= w )
    {
        take = pr[curr] + fun(curr , w - wt[curr] , pr, wt , dp);
    }
    return dp[curr][w] = max(take , not_take);       
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n , vector<int>(w + 1, -1));
    return fun(n  - 1, w , profit , weight , dp);
}

// tabulation

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>>dp(n , vector<int>(w + 1, -1));
    // initialisation
    for(int j = 0 ; j <= w ; j++)
    {
        int rem = j/weight[0];
        dp[0][j] =  profit[0] * rem;
    }
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ; j <= w ; j++ )
        {
            int not_take = dp[i-1][j];
            int take = 0 ;
            if(weight[i] <=j )
            {
                take = profit[i] + dp[i][j - weight[i]];
            }
            dp[i][j] = max(take , not_take);
        }
    }
    return dp[n-1][w];
        
}
