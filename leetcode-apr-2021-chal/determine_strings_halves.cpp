// https://leetcode.com/explore/challenge/card/april-leetcoding-challenge-2021/593/week-1-april-1st-april-7th/3699/
class Solution
{
public:
    bool halvesAreAlike(string s)
    {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size();
        int count1 = 0, count = 0;
        for (int i = 0; i < n / 2; i++)
        {
            if (st.find(s[i]) != st.end())
                count1++;
        }
        bool cond = true;
        for (int i = n / 2; i < n; i++)
        {
            if (st.find(s[i]) != st.end())
                count++;
            if (count > count1)
            {
                cond = false;
                break;
            }
        }

        if (count != count1)
            cond = false;
        return cond;
    }
};