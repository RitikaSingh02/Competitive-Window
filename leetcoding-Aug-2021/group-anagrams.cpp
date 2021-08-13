// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // ["eat","tea","tan","ate","nat","bat"]
        int n = strs.size();
        vector<vector<string>>res;
        map<map<char , int>, vector<string>>hash;
        for(auto i : strs)
        {
            string s = i;
            sort(s.begin() , s.end());
            map<char , int>hash1;
            
            for(auto c: s)
            {
                hash1[c]++;
            }
            if(hash.find(hash1)==hash.end())
            {
                hash[hash1] = {i};
            }
            else
                hash[hash1].push_back(i);
                
        }
        for(auto i : hash)
        {
            res.push_back(i.second);
            
        }
        return res;
    }
};
