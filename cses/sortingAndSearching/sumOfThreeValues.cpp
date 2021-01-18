#include<bits/stdc++.h>
using namespace std;

map<int, int > mp;
int n;
int *a;
int target;
int main() {
	cin >> n >> target;
	a = new int [n];
	for (int i = 0; i < n; i++)cin >> a[i];
	mp[a[0]] = 0 ;
	for (int i = 1; i < n - 1; i++) {
		for (int j = i + 1 ; j < n; j++) {
			if (mp.find(target - a[i] - a[j]) != mp.end()) {
				cout << i + 1 << " " << j + 1 << " " << mp[target - a[i] - a[j]] + 1;
				return 0;
			}
		}
		mp[a[i]] = i ;
	}
	cout << "IMPOSSIBLE";
}