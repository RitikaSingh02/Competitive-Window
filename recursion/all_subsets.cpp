class Solution
{
public:
    vector<vector<int>> res;
    void f(int n, vector<int> nums, vector<int> out)
    {
        //base case
        if (n == nums.size())
        {
            res.push_back(out);
            return;
        }
        // if we do not take the element

        f(n + 1, nums, out);
        out.push_back(nums[n]);
        // if we do  take the elemnet

        f(n + 1, nums, out);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        f(0, nums, {});
        return res;
    }
};