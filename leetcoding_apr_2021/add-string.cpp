//stack implementation
// https://leetcode.com/problems/add-strings/
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = min(num1.size() , num2.size());
        int m = max(num1.size() , num2.size());
        string big,small;
        if(n==m)
        {
            big = num1;
            small = num2;
        }
        else
        {
         big = (num1.size()>num2.size())?num1:num2;
         small = (num1.size()<num2.size())?num1:num2;
        }
        bool small_bool = true;
        stack<string>s ;
        int carry = 0 ;
        string res = "";
        for(int i =m-1 , j = n-1 ; i >=0 ; i-- , j--)
        {
            // if(i<0 && j <0)
            //     break;
            if(j<0)
                small_bool = false;
            if(small_bool)
            {
                int digit1 = big[i] - '0';
                int digit2 = small[j]-'0';
                cout<<big[i]<<small[j]<<" ";
                 if(carry)
                {
                    digit2+= carry;
                    s.push(to_string((digit1+digit2)%10));
                    carry = (digit1+digit2)/10;
                }
                else{
                s.push(to_string((digit1+digit2)%10));
                carry = (digit1+digit2)/10;
                }
                    
            
            }
            else{
                int digit1 = big[i]-'0';
                if(carry)
                {
                    int digit2 = carry;
                    s.push(to_string((digit1+digit2)%10));
                    carry = (digit1+digit2)/10;
                }
                else{
                    s.push(to_string(digit1));
                    
                }
            }
        }
        if(carry)
        {
            res+=to_string(carry);
        }
   
       while(!s.empty())
       {
           res+=s.top();
           s.pop();
       }
    return res;
    }
};
