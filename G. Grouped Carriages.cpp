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

int lim;
int n;
int d[N], a[N];
struct node
{
	int  r, val;
	bool operator<(const node&k)const
	{
		if (r != k.r)return r > k.r;
		else return val > k.val;
	}
} b[N];

vector<pii>edge[N];

bool solve()
{
	priority_queue<node>q;
	for (int i = 1; i <= n; ++i)
		{
			if (!q.empty() && q.top().r < i)return 0;
			int now = lim;
			sort(edge[i].begin(), edge[i].end());
			for (auto [r, val] : edge[i])
				{
					while (now && !q.empty() && q.top().r < r)
						{
							if (now >= q.top().val)now -= q.top().val, q.pop();
							else
								{
									node tmp = {q.top().r, q.top().val - now};
									now = 0;
									q.pop(), q.push(tmp);
									break;
								}
						}
					if (now >= val)now -= val;
					else
						{
							q.push({r, val - now}), now = 0;
						}
				}
			while (now && !q.empty())
				{
					if (now >= q.top().val)now -= q.top().val, q.pop();
					else
						{
							node tmp = {q.top().r, q.top().val - now};
							now = 0;
							q.pop();
							q.push(tmp);
							break;
						}
				}
		}
	return q.empty();
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	for (int i = 1; i <= n; ++i)
		{
			cin >> d[i];
			int l = max(1ll, i - d[i]), r = min(n, i + d[i]);
			edge[l].push_back({r, a[i]});
		}

	int l = *min_element(a + 1, a + 1 + n), r = *max_element(a + 1, a + 1 + n);
	int ans = r;
	while (l <= r)
		{
			lim = l + ((r - l) >> 1);
			if (solve())ans = lim, r = lim - 1;
			else l = lim + 1;
		}
	cout << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
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
