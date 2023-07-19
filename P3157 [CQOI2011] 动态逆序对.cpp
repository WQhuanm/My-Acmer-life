#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-8
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

struct node
{
	int a, b;
	bool operator<(const node&k)const
	{
		if (a != k.a)return a < k.a;
		else return b < k.b;
	}
} a[N];

int ans[N], t[N];
int n, m;
void add(int x, int w)
{
	for (int i = x; i <= m + 1; i += i & -i)t[i] += w;
}

int ask(int x)
{
	int ans = 0;
	for (int i = x; i ; i -= i & -i)ans += t[i];
	return ans;
}

void CDQ(int l, int r)
{
	if (l == r)return;
	int mid = l + ((r - l) >> 1);
	CDQ(l, mid), CDQ(mid + 1, r);
	sort(a + l, a + 1 + mid), sort(a + 1 + mid, a + 1 + r);
	int j = mid + 1;
	for (int i = l; i <= mid; ++i)
		{
			while (j <= r && a[j].a < a[i].a)add(a[j++].b, 1);
			ans[a[i].b + 1] -= ask(m + 1) - ask(a[i].b - 1), ans[0] += ask(m + 1) - ask(a[i].b - 1);
		}
	for (int i = mid + 1; i < j; ++i)add(a[i].b, -1);
	j = mid;
	for (int i = r; i >= mid + 1; --i)
		{
			while (j >= l && a[j].a > a[i].a)add(a[j--].b, 1);
			ans[a[i].b + 1] -= ask(m + 1) - ask(a[i].b), ans[0] += ask(m + 1) - ask(a[i].b);
		}
	for (int i = mid; i > j; --i)add(a[i].b, -1);
}

int vis[N];
void mysolve()
{

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].a,  a[i].b = m + 1;
			vis[a[i].a] = i;
		}
	int x;
	for (int i = 1; i <= m; ++i)cin >> x, a[vis[x]].b = i;
	CDQ(1, n);
	for (int i = 1; i <= m; ++i)ans[i] += ans[i - 1];
	for (int i = 1; i <= m; ++i)cout << ans[i] << endl;
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
