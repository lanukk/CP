#include<bits/stdc++.h>
using namespace std;

int n;
stack<pair<int, int> > s;
int *a;
int *ans;
int main() {
	cin >> n;
	ans = new int [n];
	a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	s.push({a[n - 1], n - 1});
	for (int i = n - 2; i >= 0; i--) {
		while (s.size() > 0 && a[i] < s.top().first) {
			ans[s.top().second] = i;
			s.pop();
		}
		s.push({a[i], i});
	}
	while (!s.empty()) {
		ans[s.top().second] = -1;
		s.pop();
	}
	for (int i = 0 ; i < n; i++) {
		cout << ans[i] + 1 << " ";
	}
}