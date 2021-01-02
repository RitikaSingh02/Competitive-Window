class Solution {
public:
    vector <vector<int>> res;
    set <vector<int>> s;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {     
        if(nums.size()==0)
            return res;
        
        backtrack(0,nums);
        for(vector<int> i :s)
        {
            res.push_back(i);
        }
        return res;
    }
    private:
    void backtrack(int start,vector<int>&nums)
        {
            
            if(start==nums.size())
            {
                // cout<<"s " ;
                s.insert(nums);
                // for (auto i:s)
                // {
                //     for(auto j:i)
                //     {
                //         cout<<j<<" ";
                //     }
                // }
                //     cout<<"\n";
                // return;
            }
            for(int i= start;i<nums.size();i++)
            {
                swap(nums[i],nums[start]);
                backtrack(start+1,nums);
                swap(nums[i],nums[start]);
            }
            
        }

};