#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

//#define int                long long int
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

void solve(int input)
{
	//read problem C if stuck on B for longer than 20 mins!!
	int n;
	cin >> n;
	vector< vector<pair<int, int> > > v;
	v.resize(10);
	char a[n][n];
	// for (int i = 0 ; i < n; i++)cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			v[a[i][j] - '0'].pb({i, j});
		}
	}
	for (int k = 0; k <= 9; k++) {
		int ans = 0;
		for (int i = 0; i < v[k].size(); i++) {
			for (int j = i + 1 ; j < v[k].size(); j++) {
				if (v[k][i].fi == v[k][j].fi) {

					int z = abs(v[k][i].se - v[k][j].se);
					int x = v[k][i].fi * z;
					int y = (n - v[k][i].fi - 1) * z;
					//trace4(x, y, z, ans);
					ans = max(ans, max(x, y));
				}
				else if (v[k][i].se == v[k][j].se) {
					int z = abs(v[k][i].fi - v[k][j].fi);
					int x = v[k][i].se * z;
					int y = (n - v[k][i].se - 1) * z;
					ans = max(ans, max(x, y));
				}
				else {
					//case 1:
					int z = abs(v[k][i].fi - v[k][j].fi);
					int p = max(v[k][i].se, n - v[k][i].se - 1) * z;
					int q = max(v[k][j].se, n - v[k][j].se - 1) * z;
					ans = max(ans, max(p, q));
					z = abs(v[k][j].se - v[k][i].se);
					p = max(v[k][i].fi, n - v[k][i].fi - 1) * z;
					q = max(v[k][j].fi, n - v[k][j].fi - 1) * z;
					ans = max(ans, max(p, q));
				}
			}
		}
		cout << ans << space;
	}
	cout << line;
}

signed main()
{
	jaldichal
	int x = 1;
	cin >> x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}