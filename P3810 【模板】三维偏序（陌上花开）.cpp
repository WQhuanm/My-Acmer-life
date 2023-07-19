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
const int N = 2e5 + 10;
const int mod = 998244353;
		
struct node
{
	int a, b, c, i;
	bool operator<(const node&k)const
	{
		if (a != k.a)return a < k.a;
		else if (b != k.b)return b < k.b;
		else return c < k.c;
	}
} a[N];
		
bool cmp(node&a, node&b)
{
	return a.b < b.b;
}
		
int b[N], t[N], ans[N], sum[N], val[N];
node tl[N], tr[N];
int cnt ;
		
void add(int x, int w)
{
	x = lower_bound(b + 1, b + 1 + cnt, x) - b;
	for (int i = x; i <= cnt; i += i & -i)t[i] += w;
}
		
int ask(int x)
{
	x = lower_bound(b + 1, b + 1 + cnt, x) - b;
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}
		
void CDQ(int l, int r)
{
	if (l == r)return;
	int mid = l + ((r - l) >> 1);
	CDQ(l, mid), CDQ(mid + 1, r);
	int p1 = 0, p2 = 0;
	for (int i = l; i <= mid; ++i)tl[++p1] = a[i];
	for (int i = mid + 1; i <= r; ++i)tr[++p2] = a[i];
	sort(tl + 1, tl + 1 + p1, cmp);
	sort(tr + 1, tr + 1 + p2, cmp);
	int j = 1;
	for (int i = 1; i <= p2; ++i)
		{
			while (j <= p1 && tl[j].b <= tr[i].b)
				add(tl[j].c, val[tl[j].i] + 1), ++j;
			ans[tr[i].i] += ask(tr[i].c);
		}
	for (int i = 1; i < j; ++i)add(tl[i].c, -val[tl[i].i] - 1);
}
		
void mysolve()
{
	int n, k;
	cin >> n >> k;
	cnt = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].a >> a[i].b >> a[i].c;
			a[i].i = i;
			b[++cnt] = a[i].c;
		}
	sort(a + 1, a + 1 + n);
	int len = 1;
	a[1].i = 1;
	for (int i = 2; i <= n; ++i)
		{
			if (a[i].a == a[i - 1].a && a[i].b == a[i - 1].b && a[i].c == a[i - 1].c)val[len]++;
			else a[++len] = a[i], a[len].i = len;
		}
	sort(b + 1, b + 1 + cnt);
	cnt = unique(b + 1, b + 1 + cnt) - b - 1;
	CDQ(1, len);
	for (int i = 1; i <= len; ++i)sum[ans[i] + val[i]] += val[i] + 1;
	for (int i = 0; i < n; ++i)cout << sum[i] << endl;
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
