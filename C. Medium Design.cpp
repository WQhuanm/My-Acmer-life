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

struct node
{
	int l, r;
	bool operator<(const node&k)const
	{
		return l < k.l;
	}
} a[N];

bool cmp(node &a, node &b)
{
	return a.r > b.r;
}
int n, m;
void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i].l >> a[i].r;
	sort(a + 1, a + 1 + n);
	int sum = 0, ans = 0;
	priority_queue<int, vector<int>, greater<int>>q;
	for (int  i = 1; i <= n; ++i)
		{
			if (a[i].r == m)continue;
			sum++;
			while (!q.empty() && q.top() < a[i].l)sum--, q.pop();
			ans = max(ans, sum);
			q.push(a[i].r);
		}
	sort(a + 1, a + 1 + n, cmp);
	sum = 0;
	priority_queue<int>p;
	for (int  i = 1; i <= n; ++i)
		{
			if (a[i].l == 1)continue;
			sum++;
			while (!p.empty() && p.top() > a[i].r)sum--, p.pop();
			ans = max(ans, sum);
			p.push(a[i].l);
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
