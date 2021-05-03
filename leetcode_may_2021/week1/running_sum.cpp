// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/598/week-1-may-1st-may-7th/3730/
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
     vector <int> res{nums[0]};
        int n = nums.size();
        auto it = nums.begin();
        it = next(it , 1); // did this coz nums.begin() is somewhere  just outside the vector to the left 
        // and nums.end() is somewhere just outside the vector to the right;
        
        for(int i =1 ; i<n ; i++)
        {
            it = next(it , 1);
            res.push_back(accumulate(nums.begin(), it, 0));
        }
        return res;
    }
};
