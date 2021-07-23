//https://leetcode.com/problems/generate-parentheses/
class Solution {
public:
    vector<string>res;
    void fun(int o , int c , string s)
    {
        //base cond
        if(o==0 && c==0)
        {
            res.push_back(s);
            return;
        }
        //choice of open bracket is obvious
        //whereas the choice of closing brackets only come when we have an open bracket pending to be closed i.e c>o
        if(o!=0)
        {
            fun(o-1 , c , s+"(");
        }
        if(c>o)
            fun(o , c-1 , s+")");
    }
    vector<string> generateParenthesis(int n) {
        //recursion is there as there are choices and options
        //also n-- recursive tree can be visualised
    
        //let the var o denote the count of (
        //let the var c denote count of )
        //we know that for a balanced paranthesis combo initialise o==c ==n
        fun(n , n, "");
        return res;
        
    }
};
