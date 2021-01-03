#include<bits/stdc++.h>
using namespace std;

int n;
int *a;
int m;
const int MOD = 1e9 + 7;

vector<vector<int> > dp;
int recursion(int i, int prev) {
	if (i == -1) {
		return 1;
	}
	if (a[i] != 0 && abs(prev - a[i]) > 1 ) {
		return 0;
	}
	if (dp[i][prev] != -1) {
		return dp[i][prev] % MOD;
	}
	int count = 0;
	if (a[i] != 0 ) {
		return recursion(i - 1, a[i]) % MOD;
	}
	(count += recursion(i - 1, prev) % MOD) %= MOD;
	if (prev != 1)(count += recursion(i - 1, prev - 1) % MOD) %= MOD;
	if (prev + 1 <= m)(count += recursion(i - 1, prev + 1) % MOD) %= MOD;

	return dp[i][prev] = count;
}
int main() {

	cin >> n >> m;
	a = new int [n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp.assign(n + 1, vector<int>(101, -1));
	if (a[n - 1] != 0) {
		cout << recursion(n - 2, a[n - 1]);
	}
	else {
		int count = 0 ;
		for (int i = 1; i <= m; i++) {
			(count += recursion(n - 2, i)) %= MOD;
		}
		cout << count;
	}
}
