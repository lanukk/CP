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
	int x, y;
	cin >> x >> y;
	int level = 0 ;
	if (x == y) {
		cout << "0" << line; R;
	}
	int two_x = 1;
	int count_level_x = 0;
	while (two_x  <= x) {
		two_x = two_x * 2;
		count_level_x++;
	}
	int two_y = 1;
	int count_level_y = 0;
	while (two_y <= y) {
		two_y = two_y * 2;
		count_level_y++;
	}
	int ans = 0;
	//trace(two_y);
	//trace4(x, count_level_x, y, count_level_y);
	if (count_level_y != count_level_x) {
		int a = x, counta = count_level_x, b = y, countb = count_level_y;
		if (count_level_y < count_level_x) {
			swap(a, b);
			swap(counta, countb);
		}

		while (countb != counta) {
			if (b % 2 == 0) {
				b = b / 2;
			}
			else
				b = (b - 1) / 2;
			countb--;
			ans++;
		}
		x = a, y = b;
		count_level_y = countb; count_level_x = counta;
		//trace4(x, count_level_x, y, count_level_y);
	}
	int c = 0;
	while (x != y) {
		if (x % 2 == 1) {
			x = (x - 1) / 2;
		}
		else
			x = x / 2;
		if (y % 2 == 1) {
			y = (y - 1) / 2;
		}
		else
			y = y / 2;
		c++;
	}
	ans += 2 * c;
	cout << ans << line;

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