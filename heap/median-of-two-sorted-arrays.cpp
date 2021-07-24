//https://leetcode.com/problems/median-of-two-sorted-arrays
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
      priority_queue<int>q ;
        for(auto i : nums1)
            q.push(i);
        for(auto i : nums2)
            q.push(i);
        int n = q.size();
        bool cond = (n%2==0)?true:false;
        int c = n-1; 
        if(cond)
        {
            while(!q.empty() && c>n/2)
            {   
                q.pop();
                c--;
            }
            int a = q.top();
            cout<<a;
            q.pop();
            a+=q.top();
            return double(a)/2;
        }
        while(!q.empty() && c>n/2)
            {   
                q.pop();
                c--;
            }
        
        return double(q.top());
    }
};
