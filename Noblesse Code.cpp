#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 5e5 + 10;

struct node
{
	int t;
	vector<int>v;
} a[N];

bool cmp(const node&a, const node&b)
{
	if (a.v[0] != b.v[0])return a.v[0] < b.v[0];
	int i ;
	for (i = 1; i < (int)a.v.size() && i < (int)b.v.size(); i += 2)  //祖先排前面
		{
			if (a.v[i] != b.v[i])return a.v[i] > b.v[i];//v[i]相等
			if (!a.v[i])return a.t < b.t;
			if (a.v[i + 1] < b.v[i + 1])
				{
					if (i + 2 >= (int)a.v.size())return 1;
					return a.v[i + 2] > b.v[i];
				}

			else if (a.v[i + 1] > b.v[i + 1])
				{
					if (i + 2 >= (int)b.v.size())return 0;
					return a.v[i] > b.v[i + 2];
				}

		}
	if ((int)a.v.size() == (int)b.v.size())return a.t < b.t;
	if (i  >= (int)a.v.size())return 1;
	else if (i  >= (int)b.v.size())return 0;
}

int ans[N];
int tot;

vector<int> add(int x, int y)
{
	vector<int>v;
	while (1)
		{
			if (x == y)break;
			if (x > y)v.push_back(x / y), v.push_back(1), x %= y;
			else v.push_back(y / x), v.push_back(2), y %= x;
			if (!x || !y)x = y = max(x, y);
		}
	v.push_back(x);
	reverse(v.begin(), v.end());
	return v;
}

int n, q;
void mysolve()
{
	cin >> n >> q;
	for (int i = 1; i <= q; ++i)ans[i] = 0;
	tot = 0;
	int x, y;
	for (int i = 1; i <= n; ++i)
		{
			a[++tot].t = 0;
			cin >> x >> y;
			a[tot].v = add(x, y);
		}
	for (int i = 1; i <= q; ++i)
		{
			a[++tot].t = -i;
			cin >> x >> y;
			vector v = add(x, y);
			a[tot].v = v;
			v.push_back(0);
			a[++tot] = {i, v};
		}
	sort(a + 1, a + 1 + tot, cmp);
	int cnt = 0;
	for (int i = 1; i <= tot; ++i)
		{
			if (!a[i].t)cnt++;
			else if (a[i].t > 0)ans[a[i].t] += cnt;
			else ans[-a[i].t] -= cnt;
		}
	for (int i = 1; i <= q; ++i)cout << ans[i] << endl;
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
