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
map<int, int> ans;
void recursive(int *a, int n, int l, int r, int *prefix_sum) {
	if (l >= r) {
		return;
	}
//	trace2(l, r);
	int mid = (a[l] + a[r]) / 2;
	int m = upper_bound(a, a + n, mid) - a;
	// if (a[l] == a[r])
	// 	return;
	if (m > r || m < l)
		return;
	// if (m == l) {
	// 	ans[a[l]]++;
	// 	ans[prefix_sum[r] - prefix_sum[m]];
	// 	return;
	// }
	if (l - 1 < 0) {
		ans[prefix_sum[m - 1]]++;
		ans[prefix_sum[r] - prefix_sum[m - 1]]++;
	}
	else {
		ans[prefix_sum[m - 1] - prefix_sum[l - 1]]++;
		ans[prefix_sum[r] - prefix_sum[m - 1]]++;
	}

	recursive(a, n, l, m - 1, prefix_sum);
	recursive(a, n, m, r, prefix_sum);

}

void solve(int input)
{
	//read problem C if stuck on B for longer than 20 mins!!
	int n;
	cin >> n;
	int b[n];
	int a[n];
	int q;
	cin >> q;
	for (int i = 0 ; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int prefix_sum[n];
	prefix_sum[0] = b[0];
	for (int i = 1; i < n; i++) {
		prefix_sum[i] = prefix_sum[i - 1] + b[i];
	}
	recursive(b, n, 0, n - 1, prefix_sum);
	ans[prefix_sum[n - 1]]++;
	while (q--)
	{
		int x;
		cin >> x;
		if (ans.find(x) != ans.end()) {
			cout << "Yes" << line;
		}
		else
			cout << "No" << line;
	}
	ans.clear();
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