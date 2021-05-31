class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // writing brute force
        vector<int> res ; 
        int n = nums1.size();
        int n2 = nums2.size();
        bool c;
        for(int i =0 ; i < n ; i++)
        {
            int comp = nums1[i];
            c = false;
            if(find(nums2.begin() , nums2.end() , nums2[i])!= nums2.end())
            {
                int pos = find(nums2.begin() , nums2.end() , comp) - nums2.begin();
                cout<<pos<<" ";
                for(int j =pos+1 ; j < n2 ; j++)
                {
                    if(nums2[j]>comp)
                    {
                        c = true;
                        res.push_back(nums2[j]);
                        break;
                    }
                }
            }
            if(!c)
                res.push_back(-1);           
                
        }
        return res;
    }
};
