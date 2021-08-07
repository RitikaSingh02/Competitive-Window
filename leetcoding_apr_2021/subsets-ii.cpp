class Solution {
public:
    vector<vector<int>>res;
    void fun(vector<int>nums , vector<int>out)
    {
        if(nums.size()==0)
        {
            if(find(res.begin() , res.end() , out) == res.end())
            {
                res.push_back(out);
            }
            return;
        }
        vector<int>v1 = out , v2 = out;
        v2.push_back(nums[0]);
        nums.erase(nums.begin() + 0);
        fun(nums , v1);
        fun(nums , v2);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        fun(nums , {} );
        return res;
    }
};
