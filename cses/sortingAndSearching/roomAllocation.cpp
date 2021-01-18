#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int> > v;
set<pair<int, int> > s;
map< pair<int, int>, list<int> > m;

int main() {
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
		m[v[i]].push_back(i);
	}
	int ans[n];
	int c = 1;
	sort(v.begin(), v.end());
	s.insert({v[0].second, c});

	ans[*m[v[0]].begin()] = 1;
	m[v[0]].erase(m[v[0]].begin());

	for (int i = 1; i < n; i++) {
		pair<int, int> p = *s.begin();

		if (v[i].first > p.first) {
			ans[*m[v[i]].begin()] = p.second;
			m[v[i]].erase(m[v[i]].begin());
			s.erase(p);
			s.insert({v[i].second, p.second});
		}
		else {
			c++;
			ans[*m[v[i]].begin()] = c;
			m[v[i]].erase(m[v[i]].begin());
			s.insert({v[i].second, c});
		}
	}
	cout << c << "\n";
	for (int i = 0 ; i < n; i++)cout << ans[i] << " ";
}