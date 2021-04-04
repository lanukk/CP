#include<bits/stdc++.h>
#include<math.h>
#include<set>
#include<string>
using namespace std;

#define line                  "\n"
#define all(x)                x.begin(),x.end()
#define kickstart_print(l)    cout<<"Case #"<<l<<": "
#define pb                    push_back

//max minn
template <typename T> T MIN(T first) { return first; } template <typename T, typename... Args> T MIN(T first, Args... args) { return min(first, MIN(args...)); }
template <typename T> T MAX(T first) { return first; } template <typename T, typename... Args> T MAX(T first, Args... args) { return max(first, MAX(args...)); }


vector<vector<int> > adj; int e1, e2; int N, M;


//#define int                long long int

int gcd(int a, int b);
int lcm(int a, int b);

bool check(string s) {
	stack<char> st;
	int  n = s.size();
	for (int i = 0 ; i < n; i++) {
		if (s[i] == '(')
			st.push('(');
		else {
			if (st.size() == 0)
				return 0;
			st.pop();
		}
	}
	if (st.size())
		return 0;
	return 1;
}

void solve(int input)
{
	// read problem C if stuck on B for longer than 20 mins!!
	string s;
	int n;
	cin >> s;
	n = s.length();
	int count0 = 0;
	for (char x : s)
		if (x == '0')
			count0++;

	stack<char> a, b;
	string p = "";
	string q = "";

	bool possible = 1;

	int c[n] ;
	if (s[n - 1] == '0')
		c[n - 1] = 1;
	else
		c[n - 1] = 0;


	for (int i = n - 2; i >= 0; i--) {
		s[i] == '0' ? c[i] = c[i + 1] + 1 : c[i] = c[i + 1];
	}


	for (int i = 0 ; i < n; i++) {
		if (s[i] == '1') {

			if (i + 1 < n && s[i + 1] == '0' && c[i] > 0 && c[i] % 2 == 0 && a.size() > 0 && b.size() > 0 ) {
				p = p + '(';
				q = q + '(';
				a.push('(');
				b.push('(');
			}
			else if (a.size() > 0 && b.size() > 0) {
				p = p + ')';
				q = q + ')';
				a.pop();
				b.pop();
			}
			else {
				p = p + '(';
				q = q + '(';
				a.push('(');
				b.push('(');
			}
		}
		else {
			if (a.size() == 0 && b.size() == 0) {
				possible = 0 ;
				break;
			}
			if (a.size() < b.size()) {
				p = p + '(';
				q = q + ')';
				a.push('(');
				b.pop();
			}
			else {
				p = p + ')';
				q = q + '(';
				a.pop();
				b.push('(');
			}
		}
	}
	// cout << s << line;
	if (a.size() || b.size())
		possible = 0;
	if (!possible || !check(p) || !check(q)) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < n; i++) {
		if (s[i] == '0' && p[i] == q[i]) {
			cout << "NO" << line;
			return;
		}
		else if (s[i] == '1' && p[i] != q[i]) {
			cout << "NO" << line;
			return;
		}
	}
	cout << "YES\n";
//	cout << p << line << q << line;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x = 1;
	//cin >> x;
	for (int i = 1; i <= x; i++)
		solve(i);
	return 0;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int lcm(int a, int b)
{
	return (a / gcd(a, b)) * b;
}
