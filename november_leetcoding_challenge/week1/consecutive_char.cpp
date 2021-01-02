class Solution {
public:
    int maxPower(string s) {
        int max=0,count=0;
        char ch=s[0];
        unordered_map <char,int> hash;
        //if size is 1 then simply return 1 no need to check
        if(s.size()!=1){
        for(int i=0;i<s.size();i++)
        {        
            if(s[i]==ch)
                count++;
            else
            {   
                if(count>hash[s[i-1]])
                hash[s[i-1]]=count;       
                ch=s[i];
                count=1;
            }
            
        }
        if(hash[s[s.size()-1]]<count)//to place the check on the last char which was repeated till the end but was not counted coz the string ended!!
            hash[s[s.size()-1]]=count;
        for(auto i :hash)
        {   
            cout<<i.first<<i.second<<" ";
            if( max<i.second)//you cant apply max() here coz it will give pointer error
                max=i.second;
        }
        return max;
    }
        else
        return 1;
    }
};