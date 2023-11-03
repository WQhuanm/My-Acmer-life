#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const long long mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;
//const int N = 100;
int n, m, k;
int sum[N], cnt[N][3];
struct node
{
	int l, r;
	bool operator<(const node&k)const
	{
		return r < k.r;
	}
} a[N];
bool cmp(node&a, node&b)
{
	return a.l > b.l;
}

vector<int>now[N];
void mysolve()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; ++i)sum[i] = cnt[i][0] = cnt[i][1] = cnt[i][2] = 0, now[i].clear();
	for (int i = 1; i <= m; ++i)cin >> a[i].l >> a[i].r, sum[a[i].l]++, sum[a[i].r + 1]--;
	for (int i = 1; i <= n; ++i)
		{
			sum[i] += sum[i - 1];
			for (int j = 0; j < 3; ++j)cnt[i][j] = cnt[i - 1][j];
			if (sum[i] == 0)cnt[i][0]++;
			else if (sum[i] == 1)cnt[i][1]++;
			else if (sum[i] == 2)cnt[i][2]++;
		}

	for (int i = 1; i <= m; ++i)
		{
			if (cnt[a[i].r][2] - cnt[a[i].l - 1][2] || cnt[a[i].r][1] - cnt[a[i].l - 1][1])
				for (int j = a[i].l; j <= a[i].r; ++j)now[j].push_back(i);
		}
	int ans = 0;
	for (int i = 1; i <= n; ++i)if (sum[i] == 2)
			{
				auto [l1, r1] = a[now[i][0]];
				auto  [l2, r2] = a[now[i][1]];
				int tmp = 0;
				if (l1 > l2)swap(l1, l2), swap(r1, r2);
				if (r1 < l2)//分块
					{
						tmp = cnt[n][0] + cnt[r1][1] - cnt[l1 - 1][1] + cnt[r2][1] - cnt[l2 - 1][1];
					}
				else if (r2 <= r1)//包含
					{
						tmp = cnt[n][0] + cnt[r2][2] - cnt[l2 - 1][2] + cnt[r1][1] - cnt[r2][1] + cnt[l2 - 1][1] - cnt[l1 - 1][1];
					}
				else//部分交叉
					{
						tmp = cnt[n][0] + cnt[l2 - 1][1] - cnt[l1 - 1][1] + cnt[r1][2] - cnt[l2 - 1][2] + cnt[r2][1] - cnt[r1][1];
					}
				ans = max(ans, tmp);
			}
	vector<int>pre(n + 1), mx(n + 1);
	sort(a + 1, a + 1 + m);
	int j = 1;
	for (int i = 1; i <= n; ++i)
		{
			while (j <= m && a[j].r <= i)pre[i] = max(pre[i], cnt[a[j].r][1] - cnt[a[j].l - 1][1]), ++j;
			ans = max(ans, pre[i] + mx[i - 1] + cnt[n][0]);
			mx[i] = max(mx[i - 1], pre[i]);
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
