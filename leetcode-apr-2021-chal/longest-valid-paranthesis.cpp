// https : //leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3695/
class Solution
{
public:
    int longestValidParentheses(string S)
    {
        vector stack = {-1};
        int ans = 0;
        for (int i = 0; i < S.size(); i++)
            if (S[i] == '(')
                stack.push_back(i);
            else if (stack.size() == 1)
                stack[0] = i;
            else
            {
                stack.pop_back();
                ans = max(ans, i - stack.back());
            }
        return ans;
    }
};