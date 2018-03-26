#include <bits/stdc++.h>

using namespace std;

const int N = 512;

int n, w[N][N];
int dp[N][N];

int main() {
	ios::sync_with_stdio(0);

	cin>>n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin>>w[i][j];
			dp[i][j] = w[i][j];
		}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout<<dp[i][j]<<" ";
		cout<<endl;
	}
	
	return 0;
}