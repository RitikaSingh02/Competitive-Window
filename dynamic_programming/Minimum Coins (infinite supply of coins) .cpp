// memoized :
int f(int ind , int t , vector<int>nums , vector<vector<int>>&dp)
{
    if(ind == 0)
    {
        if( t % nums[0] == 0) return t/nums[0];
        return 1e9; // something equivalent to int_max
    }
    if(dp[ind][t] != -1) return dp[ind][t];
    int not_take = 0 + f(ind - 1 , t , nums ,dp);
    int take = INT_MAX;
    if(nums[ind] <= t)
        take = 1 + f(ind , t - nums[ind] , nums , dp); // coz infinite times le skte hain kisi bhi coin ko
    
    return dp[ind][t] = min(take , not_take);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();	
    vector<vector<int>>dp(n , vector<int>(x +1 , -1));
	int ans =  f( n - 1 , x , num  , dp);
    if(ans >= 1e9) return -1;
    return ans;
}

// tabulated:

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();	
    vector<vector<int>>dp(n , vector<int>(x + 1 , 0));
	
    for(int i = 0 ; i<=x ; i++)
        if(i % num[0] == 0) dp[0][i]  = i/num[0];
    	else dp[0][i] = 1e9;
    for(int i = 1 ; i< n ; i++)
    {
        for(int j = 1 ; j <= x ; j++ )
        {
            int not_take = dp[i-1][j];
            int take = INT_MAX;
            if(num[i] <= j)
                take = 1 + dp[i][j-num[i]];
            dp[i][j] = min(take, not_take);
        }
    }
    if(dp[n-1][x] >= 1e9) return -1;
    return dp[n-1][x];
}

// space optimized

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();	
	vector<int>prev(x+1 , 0) , curr( x +1 , 0);
    for(int i = 0 ; i<=x ; i++)
        if(i % num[0] == 0) prev[i]  = i/num[0];
    	else prev[i] = 1e9;
    for(int i = 1 ; i< n ; i++)
    {
        for(int j = 1 ; j <= x ; j++ )
        {
            int not_take = prev[j];
            int take = INT_MAX;
            if(num[i] <= j)
                take = 1 + curr[j-num[i]];
            curr[j] = min(take, not_take);
        }
        prev = curr;
    }
    if(prev[x] >= 1e9) return -1;
    return prev[x];
}
