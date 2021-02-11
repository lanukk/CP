#include <iostream>
#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <climits>
#include <math.h>
#include <cassert>
#include <unordered_map>
#include <chrono>
#include <random>
#include <ctime>
#include <complex>
using namespace std;
#pragma warning(disable : 4996)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld PI = acosl(-1.0);
const ll MOD = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());


int main() {
#ifdef _DEBUG
	freopen("input1.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);
#endif
	srand(time(0));
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<ll> a(n), dp(n, INT32_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; ++i)cin >> a[i];
	for (int i = 1; i < n; ++i) {
		for (int j = i - 1; j >= max(0, i - k); --j) {
			dp[i] = min(dp[i], dp[j] + abs(a[i] - a[j]));
		}
	}
	cout << dp.back();
}