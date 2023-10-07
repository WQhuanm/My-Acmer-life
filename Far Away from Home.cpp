#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 5e5 + 10;

int n, c;
struct node
{
	int x, val, w;
	bool operator<(const node&k)const
	{
		return x > k.x;
	}
};

vector<int>a[N];

void mysolve()
{
	cin >> n >> c;
	int x, y, k;
	for (int i = 1; i <= c; ++i)a[i].clear();
	vector<int>ans;
	priority_queue<node>q;
	ll sum = 0;
	int zh = 0, fu = 0;
	for (int i = 1; i <= n; ++i)
		{
			cin >> x >> y;
			while (y--)cin >> k, a[k].push_back(x);
		}
	for (int i = 1; i <= c; ++i)
		{
			sort(a[i].begin(), a[i].end());
			for (int x = 0 ; x < (int)a[i].size(); ++x)
				{
					if (x == 0)
						{
							sum += a[i][x], fu++;
							ans.push_back(a[i][x]);
							q.push({a[i][x], 0, 1});
						}
					else
						{
							int mid = (a[i][x] + a[i][x - 1]) / 2;
							ans.push_back(mid), ans.push_back(a[i][x]);
							if (mid * 2 != a[i][x] + a[i][x - 1])q.push({mid, 1, -1});
							else q.push({mid, 0, -1});
							q.push({a[i][x], 0, 1});
						}
				}
		}
	ans.push_back(0);
	sort(ans.begin(), ans.end());
	int len = unique(ans.begin(), ans.end()) - ans.begin();
	ll res = sum;
	for (int i = 1; i < len; ++i)
		{
			sum += 1ll * (ans[i] - ans[i - 1]) * (zh - fu);
			res = min(res, sum);
			while (!q.empty() && q.top().x == ans[i])
				{
					node p = q.top();
					q.pop();
					sum += p.val, zh += p.w, fu -= p.w;
				}
		}
	cout << res << endl;
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
	return 0;
}
