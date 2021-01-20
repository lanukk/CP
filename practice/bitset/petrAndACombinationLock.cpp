//link : https://codeforces.com/problemset/problem/1097/B

#include<bits/stdc++.h>
using namespace std;

int n;
int *a;

int main() {
	cin >> n;
	a = new int[n];
	for (int i = 0 ; i < n; i++)cin >> a[i];
	for (int mask = 0 ; mask < (1 << n) ; mask++) {
		int current = 0 ;

		for (int i = 0 ; i < n; i++) {
			if (mask & (1 << i)) {
				current = (current + a[i]) % 360;
			}
			else {
				current = (current - a[i]);
				if (current < 0)current += 360;
			}

		}

		if (current == 0) {
			cout << "YES" << endl;
			return 0 ;
		}

	}
	cout << "NO" << endl;
	return 0;
}