#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e6 + 10;
int ans[N];
int f[N];
int mod = 1e4;
int main()
{
	int n;
	cin >> n;
	f[1] = 1, f[2] = 2;
	ans[1] = 2, ans[2] = 4;
	ans[0] = 1;
	for (int i = 3; i <= n; ++i)
		{
			f[i] = (f[i - 1] + f[i - 2] + 2 * ans[i - 3]) % mod;
			ans[i] = (ans[i - 1] + f[i]) % mod;
		}
	cout << f[n];
	return 0;
}
