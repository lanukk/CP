#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int, int > a, pair<int, int> b) {
	return a.second < b.second;
}
int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > v(n);
	for (int i = 0 ; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}
	int ans = 0 ;
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++) {
		int count = 1;
		int j =  i  + 1;
		while (j < n && v[j].first < v[i].second) {
			count++;
			j++;
		}
		i = j - 1;
		ans = max(ans, count);
	}
	cout << ans;
}