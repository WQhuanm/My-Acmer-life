#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 5010;
int sum[N][N];
int main()
{
	int n, m;
	cin >> n >> m;
	int x, y, v;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x >> y >> v;
			sum[x + 1][y + 1] = v;
		}
	for (int i = 1; i <= N - 1; ++i)for (int j = 1; j <= N - 1; ++j)sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
	int ans = 0;
	for (int i = m; i <= N - 1; ++i)for (int j = m; j <= N - 1; ++j)ans = max(ans, sum[i][j] - sum[i - m][j] - sum[i][j - m] + sum[i - m][j - m]);
	cout << ans << endl;
	return 0;
}
