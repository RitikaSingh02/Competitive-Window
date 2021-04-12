// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/submissions/
class Solution {
public:
    // func to print the max pow such that 3^pow is the greatest
    int max_pow(int n,int c)  
    {   
        if(n<0 || c<0)
            return 1;
        int orig = c;
        c=0;
        int ans;
        while(true)
        {
            if(pow(3,c) > n)
            { 
                ans =c-1;
                break;
            }
            if(pow(3,c)==n)
            {
                ans = c;
                break;
            }
            c++;
        }
        cout<< ans<<" ";
        
        if(ans == orig)
            return -1;
        n-= pow(3,ans);
        return max_pow(n,ans);
    }
    bool checkPowersOfThree(int n) {
        int c = INT_MAX;

        int a =max_pow(n , c);
        if(a==-1)
            return false;
        return true;
            
    }
};
