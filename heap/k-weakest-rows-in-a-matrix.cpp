// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/submissions/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        auto comp = [](vector<int> a , vector<int> b){
            
            if(a[1]==b[1])
                return a[0]>b[0];
            return a[1]>b[1];
        };
        //row len
        int row = mat.size();
        // col len 
        int col = mat[0].size();
        vector<vector<int>> v;// to store the count of 1 on row indices
        priority_queue<vector<int> , vector<vector<int>> ,decltype(comp)>q(comp);
        for(int i =0 ; i < row ; i++)
        {
            // apply binary search
            sort(mat[i].begin() , mat[i].end());
            int pos_1 = upper_bound(mat[i].begin() , mat[i].end() , 0) - mat[i].begin();
            int count = col - pos_1;
            v.push_back({i , count});
        }
        for(auto i : v)
        {
            q.push(i);
            
        }
        vector<int>res;
        int i =0 ;
        while(!q.empty() && i<k)
        {
            // cout<<q.top()[0];
            int pop = q.top()[0];
            q.pop();
            res.push_back(pop);
            i++;
        }
        return res;
    }
};
