// recursion
int fun(string s , string t , int n , int m)
{
    if(n == 0 || m == 0)
    {
        if(s[n] == t[m])
        {
            return 1;
        }
        else
            return 0;
    }
    int take = -1e9;
    if(s[n] == t[m])
    {
        take = 1 + fun(s , t , n -1 , m-1);
    }
    else
        take = max(fun(s , t , n , m - 1) , fun(s, t , n - 1 , m));
    return take;
}
int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
	return fun(s , t ,  n - 1, m - 1);
}

//memoization

int fun(string s , string t , int n , int m ,  int dp[1000][1000])
{
    if(n == 0 || m == 0)
    {
        if(s[n] == t[m])
        {
            return 1;
        }
        else
            return 0;
    }
    if(dp[n][m]!=-1) return dp[n][m];
    int take = -1e9;
    if(s[n] == t[m])
    {
        take = 1 + fun(s , t , n -1 , m-1 , dp);
    }
    else
        take = max(fun(s , t , n , m - 1 , dp) , fun(s, t , n - 1 , m , dp));
    return dp[n][m] = take;
}
int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int dp[1000][1000];
    for(int i = 0 ; i < 1000 ; i++)
    {
        for(int j = 0 ; j < 1000 ; j++)
            dp[i][j] = -1;
    }
    
	return fun(s , t ,  n - 1, m - 1 , dp);
}

//tabulation

int lcs(string s, string t)
{
    int n = s.size();
    int m = t.size();
    int dp[1000][1000];
    for(int i = 0 ; i < 1000 ; i++)
    {
        for(int j = 0 ; j < 1000 ; j++)
            dp[i][j] = -1;
    }
    
    //initialiasation
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == t[0])
        	dp[i][0] = 1;
        else
            dp[i][0] = 0;
    }
    for(int i = 0 ; i < m ; i++)
    {
        if(t[i] == s[0])
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }
    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j < m ; j++)
        {
            if(s[i] == t[j])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i][j - 1] , dp[i-1][j]);
        }
    }
    return dp[n-1][m-1];
}
