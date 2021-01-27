#include<bits/stdc++.h>
using namespace std;


int n;
int m;
vector<vector<pair<int, int>>>adj;
vector<long long int>d;
struct node {
	int a, b, w;
};
#define INF   100000000000000000LL
#define NINF -100000000000000000LL

int main() {
	cin >> n >> m;
	adj.resize(n + 1);
	node e[m];
	for (int i = 0 ; i < m; i++) {
		int x, y, wt;
		cin >> x >> y >> wt;
		adj[x].push_back({y, wt});
		e[i].a = x; e[i].b = y; e[i].w = -1 * wt;
	}
	d.assign(n + 1, INF);
	d[1] = 0;
	for (int i = 0 ; i < n - 1; i++) {
		for (int j = 0 ; j < m; j++) {
			if (d[e[j].a] < INF) {
				d[e[j].b] = min(d[e[j].b], d[e[j].a] + e[j].w);
				d[e[j].b] = max(d[e[j].b], NINF);
			}
		}
	}
	for (int i = 0 ; i < n - 1; i++) {
		for (int j = 0 ; j < m; j++) {
			if (d[e[j].a] >= INF)continue;
			d[e[j].b] = max(d[e[j].b], NINF);
			if (d[e[j].b] > d[e[j].a] + e[j].w) {
				d[e[j].b] = NINF;
			}
		}
	}
	if (d[n] == NINF) {
		cout << "-1";
		return 0;
	}
	cout << -1 * d[n];

}