#include<bits/stdc++.h>
using namespace std;

int main() {
	int n ;
	cin >> n;
	int *a = new int[n];
	int prefix[n];
	cin >> a[0];
	prefix[0] = a[0];
	for (int i = 1 ; i < n; i++)cin >> a[i], prefix[i] = prefix[i - 1] + a[i];
	int ans = 0;
	for (int i = n - 1; i >= 0 ; i--) {
		if (prefix[i] % n == 0)ans++;

		for (int j =  i - 1; j >= 0; j--) {
			if ((prefix[i] - prefix[j]) % n == 0)ans++;

		}
	}
	cout << ans;
}