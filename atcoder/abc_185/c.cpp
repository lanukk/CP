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

void solve(int input)
{
	//read problem C if stuck on B for longer than 20 mins!!
	int n;
	cin >> n;
	vector<int> a;
	a.reserve(1e5);
	int m;
	cin >> m;
	bool one = 0, nnn = 0;
	for (int i = 0 ; i < m; i++) {
		int x;
		cin >> x;
		a.pb(x);
	}

	sort(all(a));

	int minn_d = INT_MAX;
	if (a[0] != 1) {
		minn_d = min(a[0] - 1, minn_d);
	}
	if (a[m - 1] != n) {
		minn_d  = min(n - a[m - 1], minn_d);
	}

	for (int i = 1 ; i < m; i++) {
		minn_d = min(minn_d, a[i] - a[i - 1] - 1);
	}
	if (n == m)
	{cout << "0" << line; R;}
	int d = minn_d;
	int ans = 0 ;
	if (a[0] != 1) {
		ans += ceil((float)(a[0] - 1) / d);
	}
	if (a[m - 1] != n) {
		ans += ceil((float)(n - a[m - 1]) / d);
	}
	for (int i = 1; i < m; i++) {
		ans += ceil((float)(a[i] - a[i - 1] - 1) / d);
	}
	cout << ans << line;

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