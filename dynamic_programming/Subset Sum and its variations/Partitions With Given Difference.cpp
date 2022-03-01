int countPartitions(int n, int target, vector<int> &nums) {
  // same problem as TARGET SUM 
  
           // s1 - s2 = t;
        // s1 + s2 = Sum;
        // 2 * s1 = t + sum;
        // s1 = ( sum + t)/2;
  // target is the differnce
        int total_sum = accumulate(nums.begin() , nums.end() , 0);
        if(total_sum < target || (total_sum + target)%2 != 0) return 0;
        int want = (total_sum + target);
        if(want < 0) return 0; 
    /// test case : [100] and target = -200 then want = -100 jis size ka array ban nhi skta 
        want = want>>1;
        
        vector<vector<int>>dp(n , vector<int>(want + 1 , 0));
        if(nums[0] == 0) dp[0][0] = 2;// coz 0 ko loge ya nhi loge 2 choices hain same output that is 0
        else dp[0][0] = 1;
        
        if(nums[0]!= 0 && nums[0]<=want) dp[0][nums[0]] = 1;
        for(int i = 1; i < n ; i++)
        {
            for(int j = 0 ; j <= want ; j++)
            {
                int take = 0;
                int not_take = dp[i-1][j];
                if(nums[i] <= j)
                {
                    take = dp[i-1][j - nums[i]];
                }
                dp[i][j] = take + not_take;
                
            }
        }
        
        return dp[n-1][want];
}
