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
vector<string> v;

void recursion(int n, string s) {
	if (s.length() == n) {
		v.push_back(s);
		return;
	}
	recursion(n, s + '(');
	recursion(n, s + ')');
}

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
	int n ;
	string s;
	cin >> s;
	n = s.length();
	recursion(n, "");

	for (int i = 0 ; i < v.size(); i++) {
		for (int j = i ; j < v.size(); j++) {
			string p = v[i];
			string q = v[j];
			bool f =  1;
			for (int i = 0; i < n; i++) {
				if (s[i] == '0' && p[i] == q[i]) {
					f = 0;
					break;
				}
				else if (s[i] == '1' && p[i] != q[i]) {
					f = 0 ;
					break;
				}
			}
			if (f) {
				f = check(p) & check(q);
			}

			if (f) {
				cout << "YES\n";
				cout << p << line << q << line;
				return;
			}
		}
	}
	cout << "NO";

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int x = 1;
	//cin>>x;
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
