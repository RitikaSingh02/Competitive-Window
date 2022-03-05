// recursion
// exponential TC
int fun(int i , int j , vector<int>arr)
{
    if( i == j) return 0;
    int mini = 1e9;
    // do the partitions
    for(int k = i ; k <= j-1 ; k++)
    {
        int curr_steps = arr[i-1] * arr[k] * arr[j];
        int left_partition = fun( i , k , arr);
        int right_partition = fun(k + 1, j , arr);
        int total = curr_steps + left_partition + right_partition;
        mini = min(total, mini);
        
    }
    return mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    return fun(1 , N - 1 , arr);
}

//memoization
// TC : O(N3)
// as O(N2) for uk the memoization part and for each recursion call the func is running a loop of max (N)
int fun(int i , int j , vector<int>arr ,  vector<vector<int>>&dp)
{
    if( i == j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;
    // do the partitions
    for(int k = i ; k <= j-1 ; k++)
    {
        int curr_steps = arr[i-1] * arr[k] * arr[j];
        int left_partition = fun( i , k , arr , dp);
        int right_partition = fun(k + 1, j , arr , dp);
        int total = curr_steps + left_partition + right_partition;
        mini = min(total, mini);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N , vector<int>(N, -1));
    return fun(1 , N - 1 , arr , dp);
}

//tabulation
int fun(int i , int j , vector<int>arr ,  vector<vector<int>>&dp)
{
    if( i == j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int mini = 1e9;
    // do the partitions
    for(int k = i ; k <= j-1 ; k++)
    {
        int curr_steps = arr[i-1] * arr[k] * arr[j];
        int left_partition = fun( i , k , arr , dp);
        int right_partition = fun(k + 1, j , arr , dp);
        int total = curr_steps + left_partition + right_partition;
        mini = min(total, mini);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>>dp(N , vector<int>(N, -1));
//     return fun(1 , N - 1 , arr , dp);
    //initialisation
    int n = N;
    for(int i = 1 ; i < n ; i++)
        dp[i][i] = 0;
    for(int i = n-1 ; i >=1 ; i--)
    {
        // j is initialised from i + 1 as humko j ko right of i se shuru krna hai
        for(int j = i+1 ; j < n ; j++)
        {
            int mini = 1e9;
            for(int k = i ; k <= j-1 ; k++)
            {
                int curr = arr[i-1] * arr[k] * arr[j];
                int left = dp[i][k];
                int right = dp[k+1][j];
                int total = curr + left + right;
                mini = min(mini , dp[i][j]);
                dp[i][j] = mini;
            }
        }
    }
    return dp[1][n-1];
}
