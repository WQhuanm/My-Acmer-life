#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 25;

bool vis[N], vis1[N + 20], vis2[N];
int n;
int ans, a[N];
void dfs(int i)
{
	for (int j = 1; j <= n; ++j)
		{
			if (!vis[j] && !vis1[i - j + 20] && !vis2[i + j])
				{
					vis[j] = vis1[i - j + 20] = vis2[i + j] = 1;
					if (i < n)dfs(i + 1);
					else ++ans;
					vis[j] = vis1[i - j + 20] = vis2[i + j] = 0;
				}
		}
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	for (int i = 1; i <= 10; ++i)
		{
			n = i;
			ans = 0;
			dfs(1);
			a[i] = ans;
		}

	while (cin >> n && n)
		{
			cout << a[n] << endl;
		}
	return 0;
}
