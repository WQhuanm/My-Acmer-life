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

int qlen;

struct node
{
	int l, r, id;
	bool operator<(const node&k)const
	{
		if (l / qlen != k.l / qlen)return l / qlen < k.l / qlen;
		else return ((l / qlen) & 1 ? r > k.r : r < k.r);//奇偶性优化指针走位
	}
} b[N];

int a[N], cnt[N], kind[N], ans[N], len[N];
int tot;

void add(int x)
{
	cnt[x]++;
	if (cnt[x] == 1)kind[++tot] = x;
}

void del(int x)
{
	cnt[x]--;
	if (!cnt[x])--tot;
}

void mysolve()
{
	int n, m;
	cin >> n >> m;
	qlen = sqrt(m);
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= m; ++i)cin >> b[i].l >> b[i].r, b[i].id = i;
	sort(b + 1, b + 1 + m);
	ll sum = 0;
//	add(a[1]);
	for (int i = 1, l = 1, r = 0; i <= m; ++i)
		{
			len[b[i].id] = (b[i].r - b[i].l) * (b[i].r - b[i].l + 1) / 2;
			if (b[i].l == b[i].r)
				{
					ans[b[i].id] = 0;
					len[b[i].id] = 1;
					continue;
				}

			while (l > b[i].l)add(a[--l]), sum += cnt[a[l]] - 1;
//			r = max(r, l);
			while (r < b[i].r)add(a[++r]), sum += cnt[a[r]] - 1;
			while (l < b[i].l)sum -= cnt[a[l]] - 1, del(a[l++]);
			while (r > b[i].r)sum -= cnt[a[r]] - 1, del(a[r--]);
			ans[b[i].id] = sum;
			int g = __gcd(ans[b[i].id], len[b[i].id]);
			len[b[i].id] /= g, ans[b[i].id] /= g;
		}
	for (int i = 1; i <= m; ++i)
		{
			cout << ans[i] << "/" << len[i] << endl;
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
