//https://leetcode.com/problems/construct-the-rectangle/submissions/
class Solution {
public:
    vector<int> constructRectangle(int area) {
        int l=0,w=0;
        for(int i=1;i<=sqrt(area);i++)
        {
            if(area%i == 0)
            {
                l = area/i;
                w = area/l;
            }
        }
        vector<int> ans;
        ans.push_back(l);
        ans.push_back(w);
        
        return ans;
    }
};
