// https://leetcode.com/problems/palindrome-partitioning-ii/
class Solution {
public:
    int minCut(string s) {
        //brute force O(n3)
        int n = s.size();
        bool dp[n][n];
        memset( dp, false, sizeof(dp) );
        for(int g = 0 ; g < n ; g++)
        {
           for(int i = 0 , j = g ; j < n ; j++ , i++)
           {
               if(g==0)
               {
                   dp[i][j]= true;//string of len 1 is  pallindrome
               }
               else
               {
                    if(g==1)                   
                    {
                        if(s[i] == s[j])
                            dp[i][j]=true;
                        else
                            dp[i][j]=false;
                    }
                   else
                   {
                       if(s[i]==s[j] && dp[i+1][j-1])
                           dp[i][j]=true;
                   }
               }
           }
        }
        //suffix partitioning concept
        int dp1[n] ;
        dp1[0]=0;
        // for a string say "abccbccca"
        //j=1 means result of a
        //j = 3 means result of abc and so on so aur ans is in j = n
        for(int j = 1 ; j < n ; j++)
        {
            if(dp[0][j])
                dp1[j] = 0;
            else
            {
                int min_cut = INT_MAX;
                for(int i = j ; i>=1 ; i --)
                {
                    if(dp[i][j])
                    {
                        // if the suffix is pallindrome then check for the left over prefix
                        min_cut = min(min_cut , dp1[i-1]);
                    }
                }
                dp1[j] = min_cut +1;
            }
        }
        
        return dp1[n-1];
    }
};
