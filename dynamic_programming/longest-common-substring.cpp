#include <bits/stdc++.h>
using namespace std;
#define ll long long

// longest common substring
int dp[1001][1001];
int fun(string s , string s1 ,int n  , int m )
{
	for(int i =0 ; i <= n ; i++)
		dp[i][0]=0;
	for(int i =0 ; i <= m ; i++)
		dp[0][i] = 0;

	for(int i = 1 ; i<=n ; i++)
	{
		for(int j =1 ; j<=m ;j++)
		{
			if(s[i-1] == s1[j-1])
			{
				dp[i][j] = dp[i-1][j-1] +1;

			}
			else
			{
				dp[i][j] = 0;
			}
		}
	}

    int ele = 0 ;
    for(int i =0 ; i<=n ; i++)
        for(int j =0 ; j <= m ;j++)
            ele = max(dp[i][j] , ele);
	return ele;

}
int main()
{
	string s , s1; 
	cin>>s>>s1;

    cout<<fun(s , s1 , s.size() , s1.size());
}
