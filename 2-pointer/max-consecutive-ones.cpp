class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(),c2=0,counter=0;
        for(int i=0;i<n;i++)
        
        {
          
            if(nums[i]==1)
            {
                counter++;
               
            }
            else
            {
                 c2=max(c2,counter);
                counter=0;
            }
        }
        c2=max(c2,counter);
        
        return c2;
    }
};
