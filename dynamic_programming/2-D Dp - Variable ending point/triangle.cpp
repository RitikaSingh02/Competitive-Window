// recursive
int fun(int row , int col , vector<vector<int>>triangle , int n)
{
    if(row == n - 1)
    {
        // something
        return triangle[n-1][col];	
    }
    int down = triangle[row][col] + fun(row + 1 , col , triangle , n);
    int diag = triangle[row][col] + fun(row + 1 , col + 1, triangle , n);
                                      
    return min(down , diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    return fun( 0 , 0 ,triangle , n);
}

//memoized

int fun(int row , int col , vector<vector<int>>triangle , int n, vector<vector<int>>&dp)
{
    if(row == n - 1)
    {
        // something
        return triangle[n-1][col];	
    }
    if(dp[row][col]!=-1) return dp[row][col];
    int down = triangle[row][col] + fun(row + 1 , col , triangle , n , dp);
    int diag = triangle[row][col] + fun(row + 1 , col + 1, triangle , n , dp);
                                      
    return dp[row][col] = min(down , diag);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>>dp(n , vector<int>(n , -1));
    return fun( 0 , 0 ,triangle , n , dp);
}

// tabulation
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>>dp(n , vector<int>(n , -1));
    for(int i = 0 ; i < n ; i++) dp[n-1][i] = triangle[n-1][i];
    
    for(int row = n - 2; row >= 0 ; row--)
    {
        for(int col = row ; col >= 0 ; col--)
        {
            int down = triangle[row][col] + dp[row + 1 ][ col ];
    		int diag = triangle[row][col] + dp[row + 1][col + 1];
            dp[row][col] = min(down , diag);
        }
    }
   
    return dp[0][0];
    
}
