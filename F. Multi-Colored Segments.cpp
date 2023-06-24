#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
typedef pair<int, int> pii;
const int N = 3e5 + 10;

int ans[N];
int n;
void run(vector<vector<int>>a)
{
	vector<pii>l(n + 1), r(n + 1);
	for (int i = 1; i <= n; ++i)l[i].first = a[i][0], r[i].first = a[i][1], l[i].second = r[i].second = i;
	sort(l.begin() + 1, l.end());
	sort(r.begin() + 1, r.end());
	vector<pii>b;
	vector<vector<pii>>s(n + 1);
	for (int i = n; i; --i)
		{
			int lx = a[r[i].second][0], c = a[r[i].second][2];
			if (b.empty())b.push_back({lx, c});
			else if (b.size() == 1)
				{
					if (c == b[0].second)b[0].first = min(b[0].first, lx);
					else b.push_back({lx, c});
				}
			else
				{
					if (c == b[0].second)b[0].first = min(b[0].first, lx);
					else if (c == b[1].second)b[1].first = min(b[1].first, lx);
					else b.push_back({lx, c});
				}
			sort(b.begin(), b.end());
			if (b.size() > 2)b.pop_back();
			s[i] = b;
		}
	int j = 1;
	for (int i = 1; i <= n; ++i)
		{
			int p = l[i].second, lx = a[p][0], rx = a[p][1], c = a[p][2];
			while (j <= n && lx > r[j].first)++j;
			if (j > n)break;
			if (c != s[j][0].second)ans[p] = min(ans[p], max(0, s[j][0].first - rx));
			else if (s[j].size() == 2)ans[p] = min(ans[p], max(0, s[j][1].first - rx));
		}

}

void mysolve()
{

	cin >> n;
	vector a(n + 1, vector<int>(3)), b(n + 1, vector<int>(3));
	for (int i = 1; i <= n; ++i)
		{
			ans[i] = inf;
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			b[i] = a[i];
			b[i][0] = 1e9 - b[i][0], b[i][1] = 1e9 - b[i][1], swap(b[i][0], b[i][1]);
		}
	run(a), run(b);
	for (int i = 1; i <= n; ++i)cout << ans[i] << " \n"[i == n];
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
