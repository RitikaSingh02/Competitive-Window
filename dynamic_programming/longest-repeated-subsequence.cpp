int findLongestRepeatingSubSeq(string str)
{
	int n = str.length();


	int dp[n+1][n+1];
//as any string of 0 len contributes to LCS as 0
	for(int i=0;i<=n;i++){
	dp[i][0] =0;
	dp[0][i] =0;
	}



	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{

			if (str[i-1] == str[j-1] && i != j)
				dp[i][j] = 1 + dp[i-1][j-1];		//characters match but the indices not!!

			else
				dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}
	}
	return dp[n][n];
}
