// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3732/
class Solution {
public:
    int jump(vector<int>& nums) {
	vector<int> dp(nums.size(), INT_MAX);
	dp[0] = 0;
	for(int i = 0; i< nums.size()-1 ;i++){
		// update min cost for each position where index = i can reach to 
		for(int k = 1; k <= nums[i] ; k++){
			if(i+k<nums.size()){
				dp[i+k] = min(dp[i]+1, dp[i+k]);
			}   
		}
	}
	return dp[nums.size()-1];
}
};
