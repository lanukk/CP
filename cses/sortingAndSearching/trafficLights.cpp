#include<bits/stdc++.h>
using namespace std;

int n;
int m;

int main() {
	cin >> n;
	cin >> m;
	swap(n, m);
	set<pair<int, pair<int, int> > > s;
	set<int> nums;
	s.insert({m, {m, 0}});
	nums.insert(m);
	nums.insert(0);
	int a[n];
	for (int i = 0 ; i < n; i++)cin >> a[i];

	for (int i = 0 ; i < n; i++) {
		int x = a[i];
		auto it = nums.upper_bound(x);
		int r =  *it;
		it--;
		int l = *it;
		s.erase({r - l , {r , l}});
		s.insert({x - l , {x, l }});
		s.insert({r - x , {r, x}});
		pair<int, pair<int, int> > p = *s.rbegin();
		cout << p.first << " ";
		nums.insert(x);
	}
}