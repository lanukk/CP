#include<bits/stdc++.h>
using namespace std;
int n;
multiset<int> nums;

int main() {
	cin >> n;
	for (int i = 0 ; i < n; i++) {
		int x;
		cin >> x;
		auto it = nums.upper_bound(x);
		if (it == nums.end()) {
			nums.insert(x);
		}
		else {
			nums.erase(it);
			nums.insert(x);
		}
	}
	cout << nums.size();
}