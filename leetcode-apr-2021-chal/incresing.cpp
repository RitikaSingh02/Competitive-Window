class Solution
{
public:
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int c1 = 0;
        int counter;
        for (int i = 0; i < r; i++)
        {

            for (int j = 0; j < r; j++)
            {
                int start = matrix[i][j];

                int l = j - 1;
                int r = j + 1;
                int u = i - 1;
                int l = i + 1;

                if (l >= 0)
                {
                    // moving to the left

                    int initial = matrix[i][l];
                    counter = 0;
                    while (l >= 0 && initial > start)
                    {
                        start = initial;
                        initial = matrix[i][l--];
                        counter++;
                    }
                    c1 = max(c1, counter);
                }
            }
        }
    }
};