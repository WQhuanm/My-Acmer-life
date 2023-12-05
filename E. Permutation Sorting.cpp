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

int n;
int a[N], p[N], ans[N], cnt[N];
struct node
{
	int l, r;
	bool operator<(const node&k)const
	{
		return r < k.r;
	}
} b[N];

int t[N];
void add(int x)
{
	for (int i = x; i <= n; i += i & -i)t[i] += 1;
}
int ask(int x)
{
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i], p[a[i]] = i;
	for (int i = 1; i <= n ;++i)t[i] = cnt[i] = 0;
	int sum = 0;
	for (int i = 1; i <= n; ++i)
		{
			if (p[i] <= i)b[i] = {p[i], i };
			else b[i] = {p[i], i + n};
		}
	sort(b + 1, b + 1 + n);
	int j = 1;	
	for (int i = 1; i <= n; ++i)
		{
			while (j <= n && b[i].r - n >= j)sum += cnt[j++];
			int id = b[i].r <= n ? b[i].r : b[i].r - n;
			ans[id] = b[i].r - b[i].l - ask( n) + ask(b[i].l) - sum;
			add(b[i].l);
			if (b[i].r <= n)cnt[b[i].r]++;
		}
	for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
}

signed main()
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
