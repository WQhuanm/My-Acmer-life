#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
const int N = 5e5 + 10;

int n, m, k;
int a[N];
ll pre[N], sur[N];
string s;

int dp[2][N][30], lg[N];

void st()
{
	for (int i = 0; i <= n + 1; ++i)dp[0][i][0] = pre[i], dp[1][i][0] = sur[i];
	for (int j = 1; j <= lg[n + 2]; ++j)for (int i = 0; i + (1 << j) - 1 <= n + 1; ++i)
			{
				dp[0][i][j] = min(dp[0][i][j - 1], dp[0][i + (1 << (j - 1))][j - 1]); //预处理st表
				dp[1][i][j] = min(dp[1][i][j - 1], dp[1][i + (1 << (j - 1))][j - 1]); //预处理st
			}
}

ll stask(int l, int r, int p)
{
	int k = lg[r - l + 1];
	return min(dp[p][l][k], dp[p][r - (1 << k) + 1][k]); //区间查询
}

struct node
{
	int val, id;
} q[N];

void mysolve()
{
	cin >> n >> k;
	pre[0] = pre[n + 1] = sur[0] = sur[n + 1] = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	cin >> s;
	s = '$' + s;

	int head = 0, tail = 0;
	q[0] = {0, 0};
	for (int i = 1; i <= n; ++i)
		{
			while (head <= tail && q[head].id < i - k)head++;
			pre[i] = q[head].val + a[i];
			while (head <= tail && (s[i] == '1' || q[tail].val >= pre[i]))tail--;
			q[++tail] = {pre[i], i};
		}
	head = tail = 0;
	q[0] = {0, n + 1};
	for (int i = n; i; --i)
		{
			while (head <= tail && q[head].id > i + k)head++;
			sur[i] = q[head].val + a[i];
			while (head <= tail && (s[i] == '1' || q[tail].val >= sur[i]))tail--;
			q[++tail] = {sur[i], i};
		}
	st();
	cin >> m;
	int x, y;
	while (m--)
		{
			cin >> x >> y;
			int l = max(0ll, x - k), r = min(x + k, n + 1);
			for (int i = x - 1; i >= max(1ll, x - k); --i)if (s[i] == '1')
					{
						l = i;
						break;
					}
			for (int i = x + 1; i <= min(n, x + k); ++i)if (s[i] == '1')
					{
						r = i;
						break;
					}
			ll ans = y + stask(l, x - 1, 0) + stask(x + 1, r, 1);
			if (s[x] == '0' && k > 1)
				{
					for (int i = max(l, x - k + 1); i < x; ++i)
						ans = min(ans, pre[i] + stask(x + 1, min(r,i+k), 1));
				}
			cout << ans << endl;
		}
}

signed main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	lg[1] = 0;
	for (int i = 2; i <= N - 5; ++i)lg[i] = lg[i >> 1] + 1; //预处理lg
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
