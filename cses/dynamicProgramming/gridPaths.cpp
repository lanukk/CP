#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
	int n;
	cin >> n;
	char a[n][n];
	int dp[n][n];
	for (int i = 0 ; i < n; i++) {
		for (int j = 0 ; j < n; j++) {
			cin >> a[i][j];
			dp[i][j] = 0;
		}
	}
	if (n == 1 && a[0][0] == '*') {
		cout << "0";
		return 0;
	}

	dp[0][0] = 1;
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '*')continue;
			if (j - 1 >= 0 && a[i][j - 1] != '*') {
				(dp[i][j] += dp[i][j - 1]) %= MOD;
			}
			if (i - 1 >= 0 && a[i - 1][j] != '*') {
				(dp[i][j] += dp[i - 1][j]) %= MOD;
			}
		}
	}
	cout << dp[n - 1][n - 1];
}
