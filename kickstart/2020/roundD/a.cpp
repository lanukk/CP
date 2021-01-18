#include<bits/stdc++.h>
using namespace std;

void solve(int number) {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	int maxx_yet = INT_MIN;
	for (int i = 0; i < n - 1 ; i++) {

		if (a[i] > maxx_yet) {
			if (a[i] > a[i + 1]) {
				ans++;
			}
			maxx_yet = a[i];
		}

	}
	if (a[n - 1] > maxx_yet)ans++;

	cout << "Case #" << number << ": " << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve(i);
	}
}