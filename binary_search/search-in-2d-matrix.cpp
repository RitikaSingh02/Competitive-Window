//https://leetcode.com/problems/search-a-2d-matrix-ii
class Solution {
public:
    bool f(vector<vector<int>> mat , int target)
    {
        int m = mat.size();
        int n = mat[0].size();
        int i =0 ; 
        int j = n -1 ;
 
        while(i<m && j >=0)
        {
            if(mat[i][j] == target)
                return true;
            else
            {
                if(mat[i][j] > target)
                    j--;
                else
                    i++;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     
        return f(matrix , target);
    }
};
