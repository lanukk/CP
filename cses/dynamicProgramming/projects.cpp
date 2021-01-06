#include<bits/stdc++.h>
using namespace std;

int n;
struct node {
	int s, e, p;
};

node *a;
long long int dp[200010];


bool comp(node x, node y) {
	return x.s < y .s;
}

long long int recursion(int i) {
	if (i == n) {
		return 0;
	}
	if (dp[i] != -1)return dp[i];
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[mid].s <= a[i].e) {
			l = mid + 1;
		}
		else
			r = mid;
	}
	long long int p = 0;
	long long int k = 0;
	if (l != n) {
		p = recursion(l);
	}
	k = recursion(i + 1);
	return  dp[i] = max(a[i].p + p, k);
}

int main() {
	cin >> n;
	a = new node[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i].s >> a[i].e >> a[i].p;
	}
	memset(dp, -1, sizeof(dp));
	sort(a, a + n, comp);
	cout << recursion(0);
}