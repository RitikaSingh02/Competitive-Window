//https://leetcode.com/problems/target-sum/submissions/
class Solution {
public:
    int dp[22][1002];
    int f(vector<int> nums , int n , int sum )
    {
        for(int i =0 ; i <=n ; i++)
            dp[i][0] = 1;
        for(int i =1 ; i <=sum ; i++)
            dp[0][i]=0 ;
        int c =0;
        for(int i = 1 ; i<=n ; i++)
        {
            for(int j =1 ; j <=sum ;j++)
            {
                if(nums[i-1]<=j && nums[i-1]!=0)
                {
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                }
                else
                {
                    if (nums[i-1] > j || nums[i-1] == 0)
                    {   
                        dp[i][j] = dp[i-1][j];
                    }
                }

            }
              if(nums[i-1] ==0)
                    c++;
        }
        //doing so as in case of 0 the cases here are -0 or +0 
        return dp[n][sum] *pow(2,c);
        
    }
        
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum1 = accumulate(nums.begin(), nums.end() , 0);
        int sum = (sum1 + target)/2;
        
        //as if let the set is divided into S1 S2 therefore S1+S2= sum1 ; S1-S2 =target adding them sum1+target will always be +
        if ((sum1 +target) % 2 != 0){ 
            return 0;
        }
        if(sum1<target)
            return 0 ;
        return f(nums, n , sum);
        
    }
};
