//recursive
int fun(int i , int j  , int y , int r , int c ,vector<vector<int>>a)
{
    if(j < 0 || j>=c || y < 0 || y>=c) return -1e8;
   	if( i == r-1)
    {
        if(j == y)
        {
            return a[i][j];
        }
        else return a[i][j] + a[i][y];
    } 
    // for one movement of bob alice can move into three directions and vice versa
    // so for moving one row into recusion there are 9 movements possible
    
    // so exploring  all the paths gfor bothe of them simultaneously
    int maxi = -1e8;
    for(int dj1 = -1 ; dj1<=1 ; dj1++)
    {
        for(int dj2 = -1 ; dj2<=1 ; dj2++)
        {
            int val = 0;
            if(j == y)
            {
                val = a[i][y];
            }
            else
                val = a[i][y] + a[i][j];
            val+=fun(i+1 , j + dj1 , y + dj2 , r , c , a);
            maxi = max(maxi , val);
        }
    }
    return maxi;
    

}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    return fun(0 , 0 , c-1 , r , c, grid);
}

//memoized
int fun(int i , int j  , int y , int r , int c ,vector<vector<int>>a , vector<vector<vector<int>>>&dp)
{
    if(j < 0 || j>=c || y < 0 || y>=c) return -1e8;
   	if( i == r-1 )
    {
        if(j == y)
        {
            return a[i][j];
        }
        else return a[i][j] + a[i][y];
    } 
    if(dp[i][j][y]!=-1) return dp[i][j][y];
    // for one movement of bob alice can move into three directions and vice versa
    // so for moving one row into recusion there are 9 movements possible
    
    // so exploring  all the paths gfor bothe of them simultaneously
    int maxi = -1e8;
    for(int dj1 = -1 ; dj1<=1 ; dj1++)
    {
        for(int dj2 = -1 ; dj2<=1 ; dj2++)
        {
            int val = 0;
            if(j == y)
            {
                val = a[i][y];
            }
            else
                val = a[i][y] + a[i][j];
            val+=fun(i+1 , j + dj1 , y + dj2 , r , c , a ,dp);
            maxi = max(maxi , val);
        }
    }
    return dp[i][j][y] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>>dp(r , vector<vector<int>>(c , vector<int>(c , -1)));
    return fun(0 , 0 , c-1 , r , c, grid ,dp);
}

//tabulation
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>>dp(r , vector<vector<int>>(c , vector<int>(c , -1)));
    for(int j = 0 ; j < c ; j++ )    
    {
        for(int k = 0 ; k < c ; k++)
        {
            if(j == k)
            {
                dp[r-1][j][k] = grid[r-1][j];
            }
            else dp[r-1][j][k] = grid[r-1][j] + grid[r-1][k];
        }
    }
    // as the base case was n-1 because of which we initialized the table with n-1
    // aur n-1 se n-2 milega and so on
    for(int i = r-2 ; i >= 0 ; i--)
    {
        for(int j = 0 ; j < c ; j++)
        {
            for(int y = 0 ; y < c ; y++)
            {
                int maxi = -1e8;
    			for(int dj1 = -1 ; dj1<=1 ; dj1++)
                { 
                    for(int dj2 = -1 ; dj2<=1 ; dj2++)
                    {
                        int val = 0;
                        if(j == y)
                        {
                            val = grid[i][y];
                        }
                        else
                            val = grid[i][y] + grid[i][j];
                        if(j+dj1 >=0 && j+dj1 < c && y+dj2 >=0 && y + dj2 < c)
                        	val+=dp[i+1][j + dj1][y +dj2 ];
                        else val+=-1e8;
                        maxi = max(maxi , val);
                        
                    }
                }
                dp[i][j][y] = maxi;
            }
        }
    }
    return dp[0][0][c-1];
}
