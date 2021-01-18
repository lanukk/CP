#include<bits/stdc++.h>
using namespace std;


int n;
int target;
int *a;
map<long long int, int> mp;
long long int ans = 0;

int main() {
	cin >> n >> target;
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	long long int sum = 0;
	for (int i = 0 ; i < n; i++) {
		sum += a[i];
		if (mp.find(sum - target) != mp.end()) {
			ans += mp[sum - target];
		}
		if (sum == target)
			ans++;

		mp[sum]++;
	}
	cout << ans;

}