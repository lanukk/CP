#include<bits/stdc++.h>
using namespace std;

multiset<int > s;
int ans;
map<int, list<int> > mp;
int n;
struct node {
	int start, end;
};

node *a;

bool comp(node a, node b) {
	return a.end < b.end;
}
int main() {
	cin >> n;
	a = new node[n];
	for (int i = 0 ; i < n; i++) {
		cin >> a[i].start >> a[i].end;
		s.insert(a[i].start);
		mp[a[i].start].push_back(a[i].end);
	}
	sort(a, a + n, comp);
}