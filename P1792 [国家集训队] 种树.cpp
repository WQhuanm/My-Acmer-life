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
const int mod = 998244353;
const int N = 3e5 + 10;

struct node
{
	int l, r, val;
} a[N];
bool vis[N];

int n, m;
void mysolve()
{
	cin >> n >> m;

	priority_queue<pii>q;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].val;
			a[i].l = i - 1, a[i].r = i + 1;
			q.push({a[i].val, i});
		}
	if (n / 2 < m)
		{
			cout << "Error!" << endl;
			return;
		}
	ll ans = 0;
	a[1].l = n, a[n].r = 1;
	for (int i = 1; i <= m; ++i)
		{
			while (vis[q.top().second])q.pop();
			int id = q.top().second;
			ans += q.top().first;
			vis[a[id].l] = vis[a[id].r] = 1;
			q.pop();
			a[id].val = a[a[id].r].val + a[a[id].l].val - a[id].val;
			q.push({a[id].val, id});
			a[id].l = a[a[id].l].l, a[id].r = a[a[id].r].r;
			a[a[id].l].r = id, a[a[id].r].l = id;
		}
	cout << ans << endl;
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
