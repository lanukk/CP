#include<bits/stdc++.h>
using namespace std;

#define int long long int
int n;
int *a;

signed main() {
	cin >> n;
	a = new int [n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int ans = INT_MAX;
	for (int mask = 0; mask < (1 << n); mask ++) {
		int first_division_sum = 0 ;
		for (int i = 0; i < n; i++) {
			if ((mask) & (1 << i))
				first_division_sum += a[i];
		}
		int second_division_sum = sum - first_division_sum;
		ans = min(ans, abs(second_division_sum - first_division_sum));
	}
	cout << ans;
}