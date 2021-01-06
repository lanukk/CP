#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int index = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
		if (index == dp.size()) {
			dp.push_back(x);
		}
		else {
			dp[index] = x;
		}
	}
	cout << dp.size();
}