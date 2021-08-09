class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     //hashmap approach
        // [2,7,11,15], target = 9
        unordered_map<int, int>hash;
        int n = nums.size();
        //as only one pair ans is there
        for(int i = 0 ; i < n ; i++)
        {
            hash[nums[i]]=i;//2->0 , 7->1..
        }

        for(int i =0 ; i < n ; i++)
        {
            if(hash.find(target-nums[i])!=hash.end() && hash[target-nums[i]]!=i)
            {

                return {hash[target-nums[i]] , i};
            }
        }
        
        return {};      
    }
};
