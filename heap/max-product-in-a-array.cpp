//https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
class Solution {
public:

    int maxProduct(vector<int>& nums) {
        // sort the vector in desc order
        
        int n = nums.size();
        if(n==2)
            return (nums[0]-1)*(nums[1]-1);
        
        sort(nums.begin() , nums.end() , [](int a , int b){return a>b;});
        
        return (nums[0] -1)*(nums[1]-1);
    }
};
