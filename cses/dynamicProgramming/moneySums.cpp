#include<bits/stdc++.h>
using namespace std;

int n;
int *a;
bool dp[110][100010];

int main() {
	cin >> n;
	a = new int [n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0 ; j <= sum; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - a[i - 1] >= 0) {
				dp[i][j] += dp[i - 1][j - a[i - 1]];
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= sum; i++) {
		if (dp[n][i])ans++;
	}
	cout << ans << "\n";
	for (int i = 1; i <= sum; i++) {
		if (dp[n][i])cout << i << " ";
	}
}