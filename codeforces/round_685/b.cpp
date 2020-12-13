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
	int q;
	cin >> n >> q;
	string s; cin >> s;
	int leftMostZero = -1, leftMostOne = -1, rightMostOne = -1, rightMostZero = -1;
	for (int i = 0 ; i < n; i++) {
		if (leftMostOne == -1 && s[i] == '1') {
			leftMostOne = i;
		}
		if (leftMostZero == -1 && s[i] == '0') {
			leftMostZero = i;
		}
		if (leftMostZero != -1 && leftMostOne != -1)
			break;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (rightMostZero == -1 && s[i] == '0') {
			rightMostZero = i;
		}
		if (rightMostOne == -1 && s[i] == '1') {
			rightMostOne = i;
		}
		if (rightMostOne != -1 && rightMostZero != -1) {
			break;
		}
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		if (s[l] == '0' && leftMostZero < l && leftMostZero != -1) {
			cout << "YES" << line;
		}
		else if (s[l] == '1' && leftMostOne < l && leftMostOne != -1) {
			cout << "YES" << line;
		}
		else if (s[r] == '0' && rightMostZero > r) {
			cout << "YES" << line;
		}
		else if (s[r] == '1' && rightMostOne > r) {
			cout << "YES" << line;
		}
		else
			cout << "NO" << line;
	}

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