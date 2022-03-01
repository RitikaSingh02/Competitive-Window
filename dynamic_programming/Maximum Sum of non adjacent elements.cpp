// recursion 
int fun(int curr , vector<int>nums)
{
    if(curr == 0)
    {
        return nums[0]; //  if u have reached 0 then it is for sure you did not took 1 index
    }
    if(curr < 0) return 0;
    int take = nums[curr] + fun( curr - 2 , nums);
    int not_take = fun(curr - 1 , nums);
    return max(take , not_take);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    return fun( n - 1 , nums);
}

//memoization
int fun(int curr , vector<int>nums , vector<int>&dp)
{
    if(curr == 0)
    {
        return nums[0];
    }
    if(curr < 0) return 0;
    if(dp[curr] !=-1) return dp[curr];
    int take = nums[curr] + fun( curr - 2 , nums , dp);
    int not_take = fun(curr - 1 , nums , dp);
    return dp[curr] = max(take , not_take);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n , 0);
    return fun( n - 1 , nums , dp);
}

//tabulation
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int>dp(n , -1);
    dp[0] = nums[0];
    
    for(int i = 1 ; i < n ; i++)
    {
        int take = 0 , not_take = 0;
        if(i - 2 < 0) take = nums[i];
        else take = nums[i] + dp[i-2];
        not_take = dp[i-1];
        dp[i] = max(take , not_take);
    }
    return dp[n-1];
}
