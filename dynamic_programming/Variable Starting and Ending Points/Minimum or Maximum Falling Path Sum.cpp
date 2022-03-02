//recursion
int fun(vector<vector<int>>matrix , int i , int j)
{
    int m = matrix[0].size();
    int n = matrix.size();
    if(j < 0 || j >= m)  return -1e8;
    if(i == 0 ) return matrix[0][j];
   
    int curr = matrix[i][j];
    int up = curr + fun(matrix ,i - 1 , j );
    int diag_left = curr + fun(matrix , i -1 , j-1);
    int diag_right = curr + fun(matrix , i -1 , j +1);
    return max(up , max(diag_left , diag_right));
    	
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e8;
   	for(int j = 0 ; j < m ; j++)
   	{
    	maxi = max(maxi , fun(matrix , n-1 , j));
   	}
   	return maxi;
}

//memoization

int fun(vector<vector<int>>matrix , int i , int j , vector<vector<int>>&dp)
{
    int m = matrix[0].size();
    int n = matrix.size();
    if(j < 0 || j >= m)  return -1e8;
    if(i == 0 ) return matrix[0][j];
   	if(dp[i][j]!=-1) return dp[i][j];
    int curr = matrix[i][j];
    int up = curr + fun(matrix ,i - 1 , j , dp);
    int diag_left = curr + fun(matrix , i -1 , j-1 , dp);
    int diag_right = curr + fun(matrix , i -1 , j +1 , dp);
    return dp[i][j] = max(up , max(diag_left , diag_right));
    	
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e8;
    vector<vector<int>>dp( n , vector<int>( m , -1));
   	for(int j = 0 ; j < m ; j++)
   	{
    	maxi = max(maxi , fun(matrix , n-1 , j ,dp));
   	}
   	return maxi;
}

//tabulation

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int maxi = -1e8;
    vector<vector<int>>dp( n , vector<int>( m , -1));
	for(int j = 0 ; j< m; j++)
        dp[0][j] = matrix[0][j];
    for(int i = 1 ;i < n ;i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            int curr = matrix[i][j];
            int up = -1e8 , diag_left = -1e8 , diag_right = -1e8;
            up = curr + dp[i-1][j];
            
            if(j - 1 >=0 ) diag_left = curr + dp[i-1][j-1];
            if(j + 1 < m) diag_right = curr + dp[i-1][j+1];
            
            dp[i][j] = max(up , max(diag_left , diag_right));
        }
    }
    
    for(int j = 0; j < m  ; j++)
    {
        maxi = max(maxi , dp[n-1][j]);
    }
   	return maxi;
}
