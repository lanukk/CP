#include<bits/stdc++.h>
using namespace std;

struct node
{
	int v;
	int i;
};

vector<node> a;
int n;
int target;

bool comp(node a, node b) {
	return a.v < b.v;
}

int main() {
	cin >> n >> target;
	a.resize(n);
	for (int i = 0; i < n; i++)cin >> a[i].v, a[i].i = i;
	sort(a.begin(), a.end(), comp);
	for (int i = 0; i < n - 3; i++) {
		for (int j = i + 1; j < n - 2 ; j++) {
			int l =  j + 1;
			int r = n - 1;
			while (l < r) {
				int sum = a[i].v + a[j].v + a[l].v + a[r].v;
				if ( sum == target) {
					cout << a[i].i + 1 << " " << a[j].i + 1 << " " << a[l].i + 1 << " " << a[r].i + 1;
					return 0;
				}
				if (sum > target)
					r--;
				else
					l++;
			}
		}
	}
	cout << "IMPOSSIBLE";
}