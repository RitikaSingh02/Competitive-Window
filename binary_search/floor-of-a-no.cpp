// https://practice.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

class Solution{
  public:
    
    int res = -1;
    int bs(vector<long long> nums , long long s , long long e , long long search)
    {
        
        if(s<=e)
        {
            
            long long mid = (s+e)/2;
            if(mid == search)
            {   
                res = mid;
                return mid;
            }
            else
            {
                if(nums[mid] > search)
                {
                    // move to  the left side
                    res = mid -1;
                    bs(nums , s , mid -1 , search);
                }
                else
                {
                    res = mid;
                    bs(nums , mid+1 , e , search);
                }
            }
        }
        return -1;
    }
    int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        bs(v ,0 , n-1 , x );

        return res;
        
    }
};
