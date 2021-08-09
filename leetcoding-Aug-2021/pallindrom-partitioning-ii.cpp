//https://leetcode.com/problems/palindrome-partitioning-ii/
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
        //constructing a 2d array which will contain the no of cuts
        int dp1[n][n];
        for(int g = 0 ; g < n ; g++)
        {
            for(int i = 0 , j = g ; j < n ; j++, i++)
            {
                if(g==0)
                {
                    dp1[i][j]=0;
                }
                else
                {
                    if(g==1)                   
                    {
                        if(s[i] == s[j])
                            dp1[i][j]=0;
                        else
                            dp1[i][j]=1;
                    }
                    else
                    {
                        if(dp[i][j])
                        {
                            dp1[i][j]=0;
                        }
                        else
                        {
                            int min_cut = INT_MAX;
                            for(int cut_index = 0 ; cut_index < j ; cut_index++)
                            {
                                int first_part = dp1[i][cut_index];
                                int second_part = dp1[cut_index+1][j];
                                if(first_part<min_cut && second_part<min_cut)
                                {
                                    min_cut = min(first_part + second_part +1 , min_cut);
                                }
                                    
                            }
                            dp1[i][j] = min_cut;
                        }
                    }
                }
            }
        }
        return dp1[0][n-1];
    }
};
