// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        
        int i=0,j=1,c=0;
        if(nums.size()!=0)
        while(j<nums.size())
        {
            if(nums[j]!=nums[i])
            {
                i++;

                nums[i]=nums[j];
                
            }
            j++;
            c=i;
        }
        else
            return nums.size();
        return c+1;
    }
};