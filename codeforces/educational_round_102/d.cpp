#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

#define pb                 push_back
#define mk                 make_pair
//#define R                  return
#define line               "\n"
#define space              " "
#define all(x)             x.begin(),x.end()
#define V 				   vector
#define M 				   map
#define ll                 long long
#define fi                 first
#define se                 second
#define print(i,ans)       cout<<"Case #"<<i<<": "<<ans<<line
#define f(a,b,c)           for(int i = a; i < b ;i+=c)
#define fr(a,b,c)          for(int i = a; i >=b ; i = i - c)

//trace
#define tracegraph(v) 	   cout<<#v<<line;int iiii=1;for(auto &x : v){cout<<iiii<<"-> ";for(auto &xx : x)cout<<xx<<" ";cout<<endl;iiii++;}cout<<"---------------"<<line;
#define traceset(s)        cout<<#s<<line;for(auto &x: s)cout<<x<<space;cout<<"---------------"<<line;
#define tracevector(v)     cout<<#v<<line;for(auto &x: v)cout<<x<<" ";cout<<line;cout<<"---------------"<<line;
#define tracemap(mp)       cout<<#mp<<line;for(auto &x: mp){cout<<x.fi<<" "<<x.se<<line;}cout<<"---------------"<<line;
#define tracearray(arr,n)  cout<<#arr<<line;for(int i=0;i<n;i++)cout<<arr[i]<<space;cout<<line
#define trace4(a,b,c,d)    cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
#define trace3(a,b,c)      cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace2(x,y)        cout<< '>' << #x << ':' << (x) << " | " << #y << ':' << (y) << "\n"
#define trace(x)           cout << '>' << #x << ':' << (x) << "\n"


//operator overload
//pair input
template<typename T1, typename T2> istream& operator>>(istream &istream, pair<T1, T2> &p) {istream >> p.first >> p.second; return istream; }
template<typename T1, typename T2> ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) {ostream << p.first << " " << p.second; return ostream; }
//vector operations
template<typename T> istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v) cin >> it; return istream; }
template<typename T> ostream& operator<<(ostream &ostream, const vector<T> &c) {for (auto &it : c) cout << it << " "; return ostream; }
//max minn
template <typename T> T MIN(T first) { return first; } template <typename T, typename... Args> T MIN(T first, Args... args) { return min(first, MIN(args...)); }
template <typename T> T MAX(T first) { return first; } template <typename T, typename... Args> T MAX(T first, Args... args) { return max(first, MAX(args...)); }
/* stuff you should look for
	* special cases (n=1?)
	* doing something instead of nothing and stay organized
	* try solving problem C instead of B.
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
	* Never Think of BINARY SEARCH (NEVER EVER)
*/

V<V<int> > adj;
//#define int                long long int


void solve(int input)
{
	// read problem C if stuck on B for longer than 20 mins!!
	// Never Think of BINARY SEARCH (NEVER EVER)
	int n;
	cin >> n;
	int q;
	cin >> q;
	char c[n];
	int a[n];
	int x = 0 ;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (c[i] == '+')x++;
		else x--;
		a[i] = x;
	}
	int lower_range[n];
	lower_range[n - 1] = a[n - 1];
	int small = a[n - 1];
	for (int i  = n - 2; i >= 0 ; i --) {
		lower_range[i] = small;
		small = min(small, a[i]);
	}
	int upper_range[n];
	upper_range[n - 1] = a[n - 1];
	int big = a[n - 1];
	for (int i = n - 2; i >= 0 ; i--) {

		upper_range[i] = big;
		big = max(big, a[i]);
	}
	small = 0;
	int lower_range_from_left[n];
	for (int i = 0 ; i < n; i++) {
		small = min(small, a[i]);
		lower_range_from_left[i] = small;
	}
	big = 0 ;
	int upper_range_from_left[n];
	for (int i = 0 ; i < n; i++) {
		big = max(big, a[i]);
		upper_range_from_left[i] = big;
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--; r--;
		if (l == 0 && r == n - 1) {
			cout << "1" << line;
			continue;
		}
		int L;
		int R;
		int can_go_positive;
		int can_go_negative;
		if (r == n - 1) {
			R = upper_range_from_left[l - 1];
			L = lower_range_from_left[l - 1];
			cout << R - L + 1 << line; continue;
		}
		if (l == 0) {
			L = 0;
			R = 0;
			can_go_negative = lower_range[r];
			can_go_positive = upper_range[r];
			int d;
			d = a[r] - can_go_negative;
			L = min(L, 0 - d);
			d = can_go_positive - a[r];
			R = max(R, 0 + d);
			cout << R - L + 1 << line;
			continue;
		}
		L = lower_range_from_left[l - 1];
		R = upper_range_from_left[l - 1];
		can_go_negative = lower_range[r];
		can_go_positive = upper_range[r];
		int d;
		d = a[r] - can_go_negative;
		L = min(L, a[l - 1] - d);
		d = can_go_positive - a[r];
		R = max(R, a[l - 1] + d);
		cout << R - L + 1 << line;
		// 3
		// 3
		// 4
		// 2
		// 3
		// 2
		// 1
		// 2
		// 2
		// 2
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x = 1;
	cin >> x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}