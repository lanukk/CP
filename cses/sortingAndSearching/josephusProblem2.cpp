#include<bits/stdc++.h>
using namespace std;

int n ;
int k ;
list<int> l;
int main() {
	cin >> n;
	cin >> k;
	for (int i = 1; i <= n; i++) {
		l.push_back(i);
	}
	if (k == 0) {
		for (auto x : l) {
			cout << x << " ";
		}
		return 0;
	}
	int prev = -1;
	while (!l.empty()) {
		int pos = (prev + k) % l.size();
		pos = (pos + 1) % l.size();
		auto it = l.begin();
		advance(it, pos);
		cout << *it << " ";
		l.erase(it);
		prev = pos - 1;
	}
}