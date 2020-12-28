#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

#define pb                 push_back
#define mk                 make_pair
#define R                  return
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
#define int                long long int


void solve(int input)
{
	// read problem C if stuck on B for longer than 20 mins!!
	// Never Think of BINARY SEARCH (NEVER EVER)
	int n;
	cin >> n;
	int k;
	cin >> k;
	int highest_peak = 0;
	int p = - 1;
	int h[n];
	for (int i = 0 ; i < n; i++) {
		cin >> h[i];
		if (h[i] > highest_peak) {
			highest_peak = h[i];
			p = i;
		}
	}
	if (p == -1) {
		cout << "YES" << line; R;
	}
	int low = h[p], high = h[p] + k;
	bool possible = 1;
	int z = p;
	p--; //trace2(high, low);
	while (p > 0) {
		if (h[p] + k > low) {
			low = h[p];
			high = h[p] + k;
		}
		else {
			high = low + 1;
			low = high - k ;
			if (low > h[p] + k - 1) {
				possible = 0;
			}
		}
		if (high < 0 || low < 0) {
			possible = 0 ;
		}
		//trace2(high, low);
		p--;
	}
	if (h[0] + k <= low) {
		possible = 0 ;
	}
	p = z;
	low = h[p];
	high = h[p] + k;
	p++; //trace2(high, low);
	//cout << p << line;
	while (p <= n - 2) {
		if (h[p] + k > low) {
			low = h[p];
			high = h[p] + k;
		}
		else {
			high = low + 1;
			low = high - k ;
			if (low > h[p] + k - 1) {
				possible = 0;
			}
		}
		if (high < 0 || low < 0) {
			possible = 0 ;
		}
		//trace2(high, low);
		p++;
	}
	if (h[n - 1] + k <= low) {
		possible = 0 ;
	}
	if (possible) {
		cout << "YES" << line;;
	}
	else {
		cout << "NO" << line;
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