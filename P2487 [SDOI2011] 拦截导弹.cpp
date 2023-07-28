#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-9
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 5e4 + 10;

struct node
{
	int mx;
	double sum;
} t[N << 1];

struct nod
{
	int id, h, v;
} a[N];
int b[N << 1], dpf[N], dpb[N];
double cntf[N], cntb[N];
int n, len;

void add(int x, int mx, double w)
{
	x = lower_bound(b + 1, b + 1 + len, x, greater<int>()) - b;
	for (int i = x; i <= len; i += i & -i)
		{
			if (t[i].mx == mx)t[i].sum += w;
			else if (t[i].mx < mx)t[i] = {mx, w};
		}
}

void del(int x)
{
	x = lower_bound(b + 1, b + 1 + len, x, greater<int>()) - b;
	for (int i = x; i <= len; i += i & -i)t[i] = {0, 0};
}

node ask(int x)
{
	x = lower_bound(b + 1, b + 1 + len, x, greater<int>()) - b;
	node ans = {0, 0};
	for (int i = x; i; i -= i & -i)
		{
			if (t[i].mx > ans.mx)ans = t[i];
			else if (t[i].mx == ans.mx)ans.sum += t[i].sum;
		}
	return ans;
}

bool cmp_id(nod a, nod b)
{
	return a.id < b.id;
}
bool cmp_v(nod a, nod b)
{
	return a.h > b.h;
}

void CDQ1(int l, int r)
{
	if (l == r)
		{
			if (!dpf[a[l].id])dpf[a[l].id] = 1, cntf[a[l].id] = 1;
			return;
		}

	int mid = l + ((r - l) >> 1);
	sort(a + l, a + r + 1, cmp_id);
	CDQ1(l, mid);
	sort(a + l, a + mid + 1, cmp_v);
	sort(a + mid + 1, a + r + 1, cmp_v);
	int j = l;
	for (int i = mid + 1; i <= r; ++i)
		{
			while (j <= mid && a[j].h >= a[i].h)add(a[j].v, dpf[a[j].id], cntf[a[j].id]), j++;
			node tmp = ask(a[i].v);
			if (tmp.mx + 1 > dpf[a[i].id])dpf[a[i].id] = tmp.mx + 1, cntf[a[i].id] = max(tmp.sum, (double)1);
			else if (tmp.mx + 1 == dpf[a[i].id])cntf[a[i].id] += tmp.sum;
		}
	for (int i = l; i < j; ++i)del(a[i].v);
	CDQ1(mid + 1, r);
}

void CDQ2(int l, int r)
{
	if (l == r)
		{
			if (!dpb[a[l].id])dpb[a[l].id] = 1, cntb[a[l].id] = 1;
			return;
		}
	int mid = l + ((r - l) >> 1);
	sort(a + l, a + r + 1, cmp_id);
	CDQ2(mid + 1, r);
	sort(a + l, a + mid + 1, cmp_v);
	sort(a + mid + 1, a + r + 1, cmp_v);
	int j = mid + 1;
	for (int i = l; i <= mid; ++i)
		{
			while (j <= r && a[j].h >= a[i].h)add(a[j].v, dpb[a[j].id], cntb[a[j].id]), j++;
			node tmp = ask(a[i].v);
			if (tmp.mx + 1 > dpb[a[i].id])dpb[a[i].id] = tmp.mx + 1, cntb[a[i].id] = max(tmp.sum, (double)1);
			else if (tmp.mx + 1 == dpb[a[i].id])cntb[a[i].id] += tmp.sum;
		}
	for (int i = mid + 1; i < j; ++i)del(a[i].v);
	CDQ2(l, mid);
}

void mysolve()
{
	cin >> n;
	len = 0;
	for (int i = 1; i <= n; ++i)cin >> a[i].h >> a[i].v, a[i].id = i, b[++len] = a[i].v, b[++len] = -a[i].v;
	sort(b + 1, b + 1 + len);
	len = unique(b + 1, b + 1 + len) - b - 1;
	reverse(b + 1, b + 1 + len);
	CDQ1(1, n);
	for (int i = 1; i <= n; ++i)a[i].h = -a[i].h, a[i].v = -a[i].v;
	CDQ2(1, n);
	int mx = *max_element(dpf + 1, dpf + 1 + n);
	cout << mx << endl;
	double sum = 0;
	for (int i = 1; i <= n; ++i)if (dpf[i] == mx)sum += cntf[i];
	for (int i = 1; i <= n; ++i)
		{
			double cnt = 0;
			if (dpf[i] + dpb[i] == mx + 1)cnt = cntf[i] * cntb[i];
			printf("%.4lf ", cnt / sum);
		}

}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
