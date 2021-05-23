//https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size();
        int s =0 , e = n-1;
        if(nums[e]>= nums[s]) // that is the array is already sorted
            return nums[s];
        while(n--)
        {
            
            {
                
                if(nums[e-1]<nums[e])
                {
                    e--;
                }
                else
                {
                    break;
                }
                if(nums[s+1] > nums[s])
                {
                    s++;
                }
                else
                    break;                    
            }
            
        }
        
        return min(nums[s+1] , nums[e]);
    }
};

    
