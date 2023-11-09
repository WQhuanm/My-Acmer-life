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
const int N = 1e6 + 10;

struct node
{
	int a, d, i, id;
	bool operator<(const node&k)const
	{
		if (a != k.a)return a > k.a;
		else return d > k.d;
	}
} a[N], b[N];

int nx[N], ans[5];
int n, m;

int check(node a[], int n, int d)
{
	int l = 1, r = n, ans = 0;
	while (l <= r)
		{
			int mid = l + ((r - l) >> 1);
			if (a[mid].a > d)ans = a[mid].id, l = mid + 1;
			else r = mid - 1;
		}
	return ans;
}

int vis[N];

void dfs(int u)
{
	vis[u] = 2;
	if (nx[u])
		{
			if (!vis[nx[u]])dfs(nx[u]);
			if (vis[nx[u]] == 1)vis[u] = 3;
			else if (vis[nx[u]] == 3)vis[u] = 1;
		}
	else vis[u] = 1;
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i].a;
	for (int i = 1; i <= n; ++i)cin >> a[i].d, a[i].id = a[i].i = i;
	cin >> m;
	for (int i = 1; i <= m; ++i)cin >> b[i].a;
	for (int i = 1; i <= m; ++i)cin >> b[i].d, b[i].id = b[i].i = i;
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + m);
	for (int i = 1; i <= n + m; ++i)nx[i] =vis[i]= 0;
	int mx = 0, p = 0;
	for (int i = 1; i <= n; ++i)
		{
			if (a[i].d < mx)a[i].id = p;
			else mx = a[i].d, p = a[i].id;
		}
	mx = 0, p = 0;
	for (int i = 1; i <= m; ++i)
		{
			if (b[i].d < mx)b[i].id = p;
			else mx = b[i].d, p = b[i].id;
		}
	for (int i = 1; i <= n; ++i)
		{
			int id = check(b, m, a[i].d);
			if (id)nx[a[i].i] = n + id;
		}
	for (int i = 1; i <= m; ++i)
		{
			int id = check(a, n, b[i].d);
			if (id)nx[n + b[i].i] = id;
		}
	ans[1] = ans[2] = ans[3] = 0;
for(int i=1;i<=n;++i)if(!vis[i])dfs(i);
	for(int i=1;i<=n;++i)ans[vis[i]]++;
	for (int i = 1; i <= 3; ++i)cout << ans[i] << " \n"[i == 3];
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
