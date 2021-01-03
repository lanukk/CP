#include<bits/stdc++.h>
using namespace std;

int a, b;

int dp[510][510];

int recursion(int r1, int c1, int r2, int c2) {
	if (abs(r1 - r2) == abs(c1 - c2)) {
		return 0;
	}
	if (r1 > r2 || c1 > c2) {
		return 1e7;
	}
	int ans = INT_MAX;
	int positions;
	int l = r2 - r1;
	int w = c2 - c1;
	if (dp[l][w] != -1) {
		return dp[l][w];
	}
	//for veritcal cuts
	positions = c2 - c1 ;
	for (int i = 1 ; i <= ((positions + 1) / 2); i++) {
		ans = min(ans, 1 + recursion(r1, c1, r2, c1 + i - 1 ) + recursion(r1, c1 + i, r2, c2));
	}

	// //for horizontal cuts;
	positions = r2 - r1;
	for (int i = 1; i <= ((positions + 1) / 2) ; i++) {
		ans = min(ans, 1 + recursion(r1, c1, r1 + i - 1, c2) + recursion(r1 + i, c1, r2, c2));
	}
	return dp[l][w] = ans;
}

int main() {
	cin >> a >> b;
	memset(dp, -1, sizeof(dp));
	cout << recursion(0, 0, a - 1, b - 1);
}