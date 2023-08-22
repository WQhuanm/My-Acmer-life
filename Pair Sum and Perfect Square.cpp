#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
const int N = 3e5 + 10;

vector<pii>r[N];
int a[N], p[N], ans[N], t[N];
int n, q;

void add(int x)
{
	for (int i = x; i <= n; i += i & -i)t[i]++;
}

int ask(int x)
{
	if (x <= 0)return 0;
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += t[i];
	return ans;
}
void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i], p[a[i]] = i, r[i].clear(), t[i] = 0;
	cin >> q;
	int x, y;
	for (int i = 1; i <= q; ++i)cin >> x >> y, r[y].push_back({x, i});
	for (int i = 1; i <= n; ++i)
		{
			for (int j = 2; j * j <= n << 1; ++j)
				{
					y = j * j - a[i];
					if (1 <= y && y <= n && p[y] < i)add(p[y]);
				}
			for (auto [l, id] : r[i])
				{
					ans[id] = ask(n) - ask(l - 1);
				}
		}
	for (int i = 1; i <= q; ++i)cout << ans[i] << endl;
}

int32_t main()
{
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
