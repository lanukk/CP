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
//#define int                long long int

struct node {
	char left = '/';
	char right = '/';
};

void solve(int input)
{
	// read problem C if stuck on B for longer than 20 mins!!
	// Never Think of BINARY SEARCH (NEVER EVER)
	int n;
	string s;
	cin >> s;
	map<char, node> mp;
	if (s.length() == 1) {
		cout << "YES\n" << s;
		map<char, int > used;
		used[s[0]] ++;
		for (int i = 0; i < 26; i++) {
			char c = 'a' + i;
			if (used[c] == 0) {
				cout << c;
			}
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < s.length() - 1; i++) {
		if (s[i] == s[i + 1]) {
			cout << "NO\n";
			return;
		}
	}
	n = s.length();
	bool possible = 1;
	for (int i = 0; i < n - 1; i++) {
		if (mp[s[i]].left == '/') {
			mp[s[i]].left = s[i + 1];
		}
		else {
			if (mp[s[i]].right == '/') {
				if (s[i + 1] != mp[s[i]].left)
					mp[s[i]].right = s[i + 1];
			}
		}
		if (mp[s[i + 1]].left == '/') {
			mp[s[i + 1]].left = s[i];
		}
		else {
			if (mp[s[i + 1]].right == '/') {
				if (s[i] != mp[s[i + 1]].left)
					mp[s[i + 1]].right = s[i];
			}
		}
	}

	char first = '?', second = '?';

	for (auto x : mp) {
		if (x.second.right == '/') {
			if (first == '?')
				first = x.first;
			else
			{
				if (second == '?')
					second = x.first;
				else
					possible = 0;
			}
		}
		if (x.second.left == x.second.right) {
			if (first == '?') {
				first = x.first;
			}
			else {
				if (second == '?')
					second = x.first;
				else
					possible = 0;
			}
		}
	}
	if (!possible || first == '?' || second == '?') {
		cout << "NO\n";
		return;
	}
	map<char, int> used;
	string ans = "";
	ans += first;
	used[first]++;
	used['/']++;
	int count = 0;
	while (1) {
		if (count == 1500)
			break;
		node x = mp[first];
		if (used.find(x.left) == used.end()) {
			ans += x.left;
			first = x.left;
			used[x.left]++;
		}
		else if (used.find(x.right) == used.end()) {
			ans += x.right;
			used[x.right]++;
			first = x.right;
		}
		if (first == second) {

			used[second]++;
			break;
		}
		count++;
	}
	if (count == 1500) {
		cout << "NO" << line;
		return;
	}
	reverse(all(ans));
	for (int i = 0; i < 26; i++) {
		char c = 'a' + i;
		if (used[c] == 0) {
			ans += c;
		}
	}
	cout << "YES" << line;
	cout << ans << line;
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