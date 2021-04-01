// https://leetcode.com/submissions/detail/475082391/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // record the current minimum
        int cur_min = prices[0];
        int ans = 0;
        for(int i = 1; i < prices.size(); i++ ){
            // calculate the difference between current value and current minimum
            ans = max(ans, prices[i] - cur_min);
            // update minimum
            cur_min = min(cur_min, prices[i]);
        }
        return ans;
    }
};