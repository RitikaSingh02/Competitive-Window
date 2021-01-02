class Solution {
public:
    int NUM=31;
    int  positions(char c) 
        {
                return (c & NUM) ; 
        }
    int uniqueMorseRepresentations(vector<string>& words) {
        vector <string> codes={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int n=words.size();
        set <string> s1;
        int count=0;
        for(int i=0;i<n;i++)
        {
            string s="";
            for(int j=0;j<words[i].size();j++)
            {
                s+=codes[positions(words[i][j])-1];
            }
            if(s1.find(s)==s1.end())
            {
                count++;
            }
            s1.insert(s);
        }
            if(n==0)
                count=0;
        return count;
    }
};