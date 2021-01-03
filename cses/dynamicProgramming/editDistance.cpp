#include<bits/stdc++.h>
using namespace std;

string s, t;
int n; int m;

int dp[5010][5010];

// int recursion(int i, int j) {
// 	if (i == n && j == m) {
// 		return 0;
// 	}
// 	if (i == n) {
// 		return  m - j  ;
// 	}
// 	if (j == m) {
// 		return  n - i;
// 	}
// 	if (dp[i][j] != -1) {
// 		return dp[i][j];
// 	}
// 	if (s[i] == t[j]) {
// 		return dp[i][j] = recursion(i + 1, j + 1);
// 	}
// 	return dp[i][j] = 1 + min(recursion(i, j + 1), min(recursion(i + 1, j), recursion(i + 1, j + 1)));

// }

int main() {
	cin >> s >> t;
	if (s == t) {
		cout << "0";
		return 0;
	}
	n = s.length();
	m = t.length();
	//cout << n << " " << m << "\n" ;
	// memset(dp, -1, sizeof(dp));
	// cout << recursion(0, 0);
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0)
				dp[i][j] = j;
			else if (j == 0)
				dp[i][j] = i;
			else if (s[i - 1] == t[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
			}
		}
	}

	cout << dp[n ][m ];
}