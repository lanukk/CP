#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int n;
int main() {
	cin >> n;
	for (int i = 1;  i <= n; i++) {
		q.push(i);
	}
	int i = 1;
	while (!q.empty()) {
		if (i == 1) {
			int x = q.front();
			q.pop();
			q.push(x);
		}
		else {
			cout << q.front() << " ";
			q.pop();
		}
		i = (i + 1) % 2;
	}

}