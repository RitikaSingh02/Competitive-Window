// recursion
int fun(int curr , int left , vector<int>price)
{
    if(curr == 0)
    {
        return left * price[0];
    }	
    int curr_val = price[curr];
    int take = -1e9;
    int rod_len = curr + 1;
    if(rod_len <= left)
    	take = curr_val + fun(curr , left - rod_len , price );
    int not_take = 0 + fun(curr - 1 , left, price);
    return max(take , not_take);
}
int cutRod(vector<int> &price, int n)
{
	return fun( n - 1 , n , price );
}

//memoization
int fun(int curr , int left , vector<int>price , vector<vector<int>>&dp)
{
    if(curr == 0)
    {
        return left * price[0];
    }	
    if(dp[curr][left]!=-1) return dp[curr][left];
    int curr_val = price[curr];
    int take = -1e9;
    int rod_len = curr + 1;
    if(rod_len <= left)
    	take = curr_val + fun(curr , left - rod_len , price , dp);
    int not_take = 0 + fun(curr - 1 , left, price , dp );
    return dp[curr][left] = max(take , not_take);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>>dp(n , vector<int>(n + 1 , -1));
	return fun( n - 1 , n , price , dp);
}

// tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>>dp(n , vector<int>(n + 1 , -1));
// 	return fun( n - 1 , n , price , dp);
    // initialisation
    for(int i = 0 ; i <= n ; i++)
        dp[0][i] = i * price[0];
    // i denotes curr that is current index
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 0 ; j <= n ; j++ )
        {
            int not_take = dp[i - 1][j];
            int take = -1e9;
            int rod_len = i + 1;
            if(rod_len <= j)
            {
                int curr_val = price[i];
                take = curr_val + dp[i][j - rod_len];
            }
            dp[i][j] = max(take , not_take);
        }
    }
    return dp[n-1][n];
}
