#include <bits/stdc++.h>
#define ll long long
using namespace std;

int counter =0 ;
void bs(vector <int> nums , int s , int e , int search)
{
    int mid = (s+e)/2;
    if(search == nums[mid])
    {
        counter++;
        int l = mid -1 , r = mid+1;
        if(s!=e)
        {
            if(l >=0 && nums[l]==nums[mid])
            {
                bs(nums , s , l , search);

            }
            if(r < nums.size() && nums[r] == nums[mid])
            {
                bs(nums , r , e , search);
            }
        }
        return;
    }
    if(search > nums[mid])
        bs(nums , mid+1 , e , search);
    else
        bs(nums , s , mid-1 , search);
}
int main()
{
    // recursive code for binary search 
    
    vector <int> v{2,4 , 10 , 10, 10 ,10 , 18 , 20};
    bs(v , 0 , v.size()-1 , 10);
    cout<<counter; // return the no. of occurences of 10
    
}
