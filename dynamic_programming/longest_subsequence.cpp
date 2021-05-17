class Solution {
public:
    int dp[1001][1001];
    int fun(string s1 , string s2 , int n1 , int n2)
    {
        //memoized
//         base case
//         if(n1==0 || n2 ==0)
//             return 0;
//         if(dp[n1][n2]==-1)
//         {
//             if(s1[n1-1] == s2[n2-1])
//             {
//                 s1 = s1.substr(0 , n1-1);
//                 s2 = s2.substr(0 , n2-1);
//                 dp[n1][n2] = 1+ fun(s1 , s2 , n1-1 , n2-1);
//             }
//             else
//             {
//                 dp[n1][n2] =  max(fun(s1, s2.substr(0 , n2-1) , n1 , n2-1),fun(s1.substr(0 , n1-1), s2 , n1-1 , n2));             

//             }
//         }
//      return dp[n1][n2];
        
        
        //TOP DOWN
        for(int i = 0 ; i <=n1 ; i++)
            dp[i][0] = 0;
        for(int i = 0 ; i <=n2 ; i++)
            dp[0][i] = 0;

        for(int i =1 ; i<=n1 ; i++)
        {
            for(int j = 1; j <=n2 ; j++)
            {
             
                if(s1[i-1] == s2[j-1])
                {
       
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] =  max(dp[i-1][j],dp[i][j-1]);             

                }   
            }
        }
        return dp[n1][n2];
    } 

    
    int longestCommonSubsequence(string s1, string s2) {
        //memest(dp , -1 , sizeof(dp));
        return fun(s1, s2 , s1.size() , s2.size())    ;
};
};
