//iterative approach
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        //iterative
        vector<vector<int>>res(rowIndex +1);
        for(int i = 0 ; i <=rowIndex ; i++)
        {
            res[i].resize(i+1);
            res[i][0] = res[i][i] = 1;
            //res[i][i] coz i+1 ki array hai to last ele hoga i aur wo 1 hi hona hai!
            for(int j = 1 ; j<i ; j++)
            {
                res[i][j] = res[i-1][j-1]+res[i-1][j];
            }
        }
        return res[rowIndex];
    }
};
