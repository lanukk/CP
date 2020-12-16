#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

#define int                long long int
#define jaldichal          ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb                 push_back
#define mk                 make_pair
#define R                  return
#define line               "\n"
#define tracearray(arr,n)  cout<<"Values in array: ";for(int i=0;i<n;i++)cout<<arr[i]<<space;cout<<line
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace2(x,y) cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n"
#define trace(x) cout << '>' << #x << ':' << (x) << "\n"
#define space              " "
#define all(x)             x.begin(),x.end()
#define w(x)               int x;cin>>x;for(int i=1;i<=x;i++)
#define vi                 vector<int>
#define setbits(x)         __builtin_popcountll(x)
#define ll                 long long
#define fi                 first
#define se                 second
#define print(i,ans)       cout<<"Case #"<<i<<": "<<ans<<line

/* stuff you should look for
	* special cases (n=1?)
	* doing something instead of nothing and stay organized
	* try solving problem C instead of B.
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/

int calc(vi a, int m, int n, int k) {
	int ans = 0 ;
	int d = k;
//	int ans = 0 ;
	if (a[0] != 1) {
		ans += ceil((long double)(a[0] - 1) / d);
		if (a[0] - 1 < d) {
			return -1;
		}
	}
	if (a[m - 1] != n) {
		ans += ceil((long double)(n - a[m - 1]) / d);
		if (n - a[m - 1] < d) {
			return -1;
		}
	}
	for (int i = 1; i < m; i++) {
		ans += ceil((long double)(a[i] - a[i - 1] - 1) / d);
		if (a[i] - a[i - 1] - 1 < d) {
			return -1;
		}
	}
	return ans;

}
void solve(int input)
{
	//read problem C if stuck on B for longer than 20 mins!!
	int n;
	cin >> n;
	vector<int> a;
	a.reserve(1e5);
	int m;
	cin >> m;
	for (int i = 0 ; i < m; i++) {
		int x;
		cin >> x;
		a.pb(x);
	}
	if (m == 0) {
		cout << "1" << line; R;
	}
	sort(all(a));
	int l = 1, r = n ;
	if (n == m)
	{cout << "0" << line; R;}

	int ans = INT_MAX;
	while (l <= r) {
		int mid = (l + r) / 2;
		int z = calc(a, m, n, mid);

		if (z != -1) {
			ans = min(ans, z);
			l = mid + 1;
		}
		else
			r = mid ;
	}

	cout << l << line;

	cout << l << line;

}

signed main()
{
	jaldichal
	int x = 1;
	//cin>>x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}