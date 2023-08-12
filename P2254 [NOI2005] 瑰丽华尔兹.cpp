#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 210;

struct node
{
	int val, num;
} q[N];
int n, m, k, x, y;
char a[N][N];
int dp[N][N];
void mysolve()
{
	cin >> n >> m >> x >> y >> k;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)cin >> a[i][j], dp[i][j] = -inf;
	dp[x][y] = 0;
	int s, t, d;
	while (k--)
		{
			cin >> s >> t >> d;
			int num = t - s + 1;
			if (d == 1)//up
				{
					for (int i = 1; i <= m; ++i)
						{
							int head = 1, tail = 0;
							for (int j = n, cnt = 0; j; --j, ++cnt)
								{
									if (a[j][i] == '.')
										{
											int cur = dp[j][i] - cnt;
											while (head <= tail && q[head].num < cnt - num)head++;
											while (head <= tail && q[tail].val < cur)tail--;
											q[++tail] = {cur, cnt};
											dp[j][i] = q[head].val + cnt;
										}
									else head = tail + 1;
								}

						}
				}
			else if (d == 2)//down
				{
					for (int i = 1; i <= m; ++i)
						{
							int head = 1, tail = 0;
							for (int j = 1, cnt = 0; j <= n; ++cnt, ++j)
								{
									if (a[j][i] == '.')
										{
											int cur = dp[j][i] - cnt;
											while (head <= tail && q[head].num < cnt - num)head++;
											while (head <= tail && q[tail].val < cur)tail--;
											q[++tail] = {cur, cnt};
											dp[j][i] = q[head].val + cnt;
										}
									else head = tail + 1;
								}

						}
				}
			else if (d == 3)//left
				{
					for (int i = 1; i <= n; ++i)
						{
							int head = 1, tail = 0;
							for (int j = m, cnt = 0; j; ++cnt, --j)
								{
									if (a[i][j] == '.')
										{
											int cur = dp[i][j] - cnt;
											while (head <= tail && q[head].num < cnt - num)head++;
											while (head <= tail && q[tail].val < cur)tail--;
											q[++tail] = {cur, cnt};
											dp[i][j] = q[head].val + cnt;
										}
									else head = tail + 1;
								}

						}
				}
			else//right
				{
					for (int i = 1; i <= n; ++i)
						{
							int head = 1, tail = 0;
							for (int j = 1, cnt = 0; j <= m; ++cnt, ++j)
								{
									if (a[i][j] == '.')
										{
											int cur = dp[i][j] - cnt;
											while (head <= tail && q[head].num < cnt - num)head++;
											while (head <= tail && q[tail].val < cur)tail--;
											q[++tail] = {cur, cnt};
											dp[i][j] = q[head].val + cnt;
										}
									else head = tail + 1;
								}

						}
				}
		}
	int mx = 0;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= m; ++j)mx = max(mx, dp[i][j]);
	cout << mx << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
