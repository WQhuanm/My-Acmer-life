#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 1010;
ll f[N];
int main()
{
	f[0] = 1;
	int n, m, x;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			for (int i = m; i >= 0; --i)
				{
					f[i + x] += f[i];
				}
		}
	cout << f[m];
}
