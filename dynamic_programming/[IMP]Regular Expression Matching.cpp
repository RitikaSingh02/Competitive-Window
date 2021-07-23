// https://leetcode.com/problems/regular-expression-matching/
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=p.length(); // making it rows
        int m=s.length(); // making its coloumns
        
        bool dp[n+1][m+1];
        
        for(int i=0;i<n+1;i++){
            
            for(int j=0;j<m+1;j++){
                
                if(i==0 && j==0){
                    // for the first block
                    dp[i][j]=true;
                }
                
                else if(i==0){
                    // first row with false
                    dp[i][j]=false;
                }
                
                else if(j==0){
                    // first coloumn
                    char ch=p[i-1];
                    
                    if(ch=='*'){
                        // if star then check two row above
                        dp[i][j]=dp[i-2][j];
                    }
                    
                    else{
                        // otherwise directly false
                        dp[i][j]=false;
                    }
                }
                
                else{
                    // for other blocks
                    char ch=p[i-1];
                    char chs=s[j-1];
                    
                    if(ch=='*'){
                        // ye toh hr baar krna he hai hume
                        dp[i][j]=dp[i-2][j];
                        
                        char check=p[i-2];
                        
                        if(check=='.' || check==chs){
                            // if same then taking or of both 
                            dp[i][j]=dp[i][j] || dp[i][j-1];
                        }
                    }
                    
                    else if(ch=='.'){
                        // checking only diagonally
                        dp[i][j]=dp[i-1][j-1];
                    }
                    
                    else if(ch==chs){
                        // checking only diagonally
                        dp[i][j]=dp[i-1][j-1];
                    }
                    
                    else{
                        // not equal
                        dp[i][j]=false;
                    }
                    
                    
                }
            }
        }
        
        return dp[n][m];
    }
};
