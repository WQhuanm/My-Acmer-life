#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

int fa[N];

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}

struct node
{
	int k, id;
	bool operator<(const node&k1)const
	{
		if (k != k1.k)return k < k1.k;
		else return id < k1.id;
	}
} a[N];

int t[N], vis[N];
int n, m, q, x, y;
void add(int x, int w)
{
	for (int i = x; i <= n; i += i & -i)t[i] += w;
}

int ask(int x)
{
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}
void mysolve()
{

	string s;
	cin >> n >> m >> q >> s;
	s = '$' + s;
	for (int i = 1; i <= n + 1; ++i)fa[i] = i, a[i].k = inf, a[i].id = i;
	for (int i = 1; i <= m; ++i)
		{
			cin >> x >> y;
			for (int j = find(x); j <= y; j = find(j))
				{
					a[j].k = i;
					fa[j] = j + 1;
				}
		}
	sort(a + 1, a + 1 + n);
	int len = 0;
	for (int i = 1; i <= n; ++i)
		{
			vis[a[i].id] = i;
			if (a[i].k < inf)len++;
			if (s[a[i].id] == '1')add(i, 1);
		}
	while (q--)
		{
			cin >> x;
			int p = vis[x];
			if (s[x] == '1')s[x] = '0', add(p, -1);
			else s[x] = '1', add(p, 1);
			int cnt = min(len, ask(n));
			cout << cnt - ask(cnt) << endl;
		}

}

int32_t main()
{
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
