// https://leetcode.com/problems/partition-equal-subset-sum/
unordered_map<string, bool> dp;

bool solve(vector<int> &nums, int i, int sum){
    
    string key = to_string(i) + "|" + to_string(sum);
    
    if(dp.find(key) != dp.end()){
        return dp[key];
    }
    
    if(sum == 0){
        return dp[key] = true;
    }
    
    if(i == nums.size()){
        return dp[key] = false;
    }
    
    bool ans;
    
    if(nums[i] <= sum){
    	    //either we take the element or we leave it
        ans = solve(nums, i+1, sum-nums[i]) || solve(nums, i+1, sum);
    }
    else{
	    //if current is greater then the sum then we will skip it
      
        ans = solve(nums, i+1, sum);
    }
    
    return dp[key] = ans;
}

bool canPartition(vector<int>& nums) {
    int n = nums.size();
    if(n < 2){
        return false;
    }
    
    int sum = 0;
    
    for(int i=0; i<n; i++){
        sum += nums[i];
    }
    
	//if sum is odd then its not possible for us to split it into two equal partitions
    if(sum % 2){
        return false;
    }
    
    return solve(nums, 0, sum/2);
}
