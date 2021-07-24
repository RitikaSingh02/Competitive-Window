//https://leetcode.com/problems/median-of-two-sorted-arrays
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
//       priority_queue<int>q ;
//         for(auto i : nums1)
//             q.push(i);
//         for(auto i : nums2)
//             q.push(i);
//         int n = q.size();
//         bool cond = (n%2==0)?true:false;
//         int c = n-1; 
//         if(cond)
//         {
//             while(!q.empty() && c>n/2)
//             {   
//                 q.pop();
//                 c--;
//             }
//             int a = q.top();
//             cout<<a;
//             q.pop();
//             a+=q.top();
//             return double(a)/2;
//         }
//         while(!q.empty() && c>n/2)
//             {   
//                 q.pop();
//                 c--;
//             }
        
//         return double(q.top());
//     }
// };

//2-pointer approach
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //2-pointer appproach
        int i = 0 , j =0 ;
        int n = nums2.size() , m = nums1.size();
        int counter = n + m ;
        bool cond = ((counter)%2 == 0)?true:false;//even = true else false;
        vector<int>res;
        while( i < m && j < n && res.size()<= counter/2 )
        {
            if(nums1[i] < nums2[j])
            {
                res.push_back(nums1[i]);
                i++;
            }else
            {
                if(nums1[i] > nums2[j])
                {
                    res.push_back(nums2[j]);
                    j++;
                }
                else
                {
                    //they are equal
                    res.push_back(nums1[i]);
                    if(res.size()<(counter/2)+1)
                        res.push_back(nums2[j]);
                    i++;
                    j++;
                }
            }
        }
        // cout<<res.size();
        for(auto i : res)
            cout<<i;
        if(res.size()<((counter/2)+1))
        {
            while(i<m && res.size()<(counter/2)+1)
            {
                res.push_back(nums1[i]);
                i++;
            }
            while(j<n && res.size()<(counter/2)+1)
            {
                res.push_back(nums2[j]);
                j++;
            }
        }
        if(cond)
        {
            //even
            return double(res[res.size() -1] + res[res.size()-2])/2;
            
        }
        return double(res[res.size()-1]);
    }
};
