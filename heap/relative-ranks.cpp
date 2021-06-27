//https://leetcode.com/problems/relative-ranks/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        // scores are unique
        // create a priority queue [max-heap]
        priority_queue<int> q;
        for(auto i : score)
        {
            q.push(i);
            
        }
        vector<string>res(score.size() , "");
        for(int i =0 ; i <score.size(); i++)
        {
            int pop = q.top();
            q.pop();
            int pos = find(score.begin() , score.end() , pop) - score.begin();
            if(i<3)
            {
                switch(i){
                  case 0: res[pos]="Gold Medal"; break;
                  case 1: res[pos]="Silver Medal"; break;
                  case 2: res[pos]="Bronze Medal"; break;
                }
            }
            else
            {
                res[pos] = to_string(i+1);
            }
            
        }
        return res;
    }
};
