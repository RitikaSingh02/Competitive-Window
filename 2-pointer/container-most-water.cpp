// https://leetcode.com/problems/container-with-most-water/submissions/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=1,n=height.size(),ar=0;
        j=n-1;
        while(i <n && j>=0 && j>i)
        {
            int p=min(height[i],height[j])*(j-i);
            if(ar< p)
                ar=p;
            if (height[i]<height[j])
                i++;
            else
                j--;
        }
        return ar;
    }
};