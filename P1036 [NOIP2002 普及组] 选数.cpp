#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 25;

int a[N];
ll cnt = 0;
int n, k;
bool mjud(int x)
{
	if (x < 5)
		{
			if (x == 2 || x == 3)return 1;
			else return 0;
		}
	if (x % 6 != 1 && x % 6 != 5)return 0;
	for (int i = 5; i * i <= x; i += 6)
		{
			if (x % i == 0 || x % (i + 2) == 0)return 0;
		}
	return 1;
}

void dfs(int x, int i, ll ans)
{
	if (x == k)
		{
			cnt += mjud(ans);
			return ;
		}
	if (i <= n)
		{
			dfs(x + 1, i + 1, ans + a[i]);
			dfs(x, i + 1, ans);
		}

}

int main()
{

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	dfs(0, 1, 0);
	cout << cnt << endl;
	return 0;
}
