#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int f[N], ans[N];
int main()
{
	int n;
	cin >> n;
	f[1] = ans[1] = 1;
	for (int i = 2; i <= n; ++i)
		{
			f[i] = 1 + ans[i / 2];
			ans[i] = ans[i - 1] + f[i];
		}
	cout << f[n];
	return 0;
}
