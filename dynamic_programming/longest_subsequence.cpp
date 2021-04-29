class Solution
{
public:
    int memo[1001][1001];

    int lcs(string s1, string s2, int n1, int n2, int memo[10001][1001])
    {
        if (memo[n1][n2] != -1)
            return memo[n1][n2];
        if (n1 == 0 || n2 == 0)
            return 0;
        if (s1[n1 - 1] == s2[n2 - 1])
            memo[n1][n2] = 1 + lcs(s1, s2, n1 - 1, n2 - 1, memo);
        else
        {
            memo[n1][n2] = max(lcs(s1, s2, n1 - 1, n2, memo), lcs(s1, s2, n1, n2 - 1, memo));
        }

        return memo[n1][n2];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        for (int i = 0; i < n1 + 1; i++)
            for (int j = 0; j < n2 + 1; j++)
                memo[i][j] = -1;

        return lcs(text1, text2, n1, n2, memo);
    }
};