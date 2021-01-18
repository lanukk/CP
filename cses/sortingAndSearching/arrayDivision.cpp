#include<bits/stdc++.h>
using namespace std;
#define int long long int
int n;
int *a;
int k;


bool check(int mid) {
	int sum = 0 ;
	int div = 1 ;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (a[i] > mid)return 0;
		if (sum > mid) {
			sum = a[i];
			div++;
		}
	}

	if (div <= k)
		return 1;
	return 0;
}

signed main() {
	cin >> n >> k;
	a = new int[n];
	int sum = 0 ;
	for (int i = 0; i < n; i++)cin >> a[i], sum += a[i];
	int l = 1, r = sum;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			r = mid;
		}
		else
			l = mid + 1;
	}
	cout << l;
}