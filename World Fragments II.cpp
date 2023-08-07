#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
const int N = 3e5 + 10000;

struct tree
{
	vector<int>to, back;
} t[N];

vector<int>to[N], back[N];
int n = N - 10;
bool vis[10];

void bfs(int s, int l, int r)
{
	t[s].to.resize(r - l + 1), t[s].back.resize(r - l + 1);
	for (int i = 0; i < r - l + 1; ++i)t[s].to[i] = t[s].back[i] = inf;
	queue<int>q;
	t[s].to[s - l] = t[s].back[s - l] = 0;
	q.push(s);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto v : to[u])if (v >= l && v <= r && t[s].to[v - l] == inf)q.push(v), t[s].to[v - l] = t[s].to[u - l] + 1;
		}

	q.push(s);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (auto v : back[u])if (v >= l && v <= r && t[s].back[v - l] == inf)q.push(v), t[s].back[v - l] = t[s].back[u - l] + 1;
		}
}

void solve(int l, int r)
{
	if (l > r)return;
	int mid = l + ((r - l) >> 1);
	int ml = max(l, mid - 4), mr = min(r, mid + 4);
	for (int i = ml; i <= mr; ++i)bfs(i, l, r);
	solve(l, ml - 1), solve(mr + 1, r);
}

int ask(int x, int y, int l, int r)
{
	if (l > r)return inf;
	int ans = inf;
	int mid = l + ((r - l) >> 1);
	int ml = max(l, mid - 4), mr = min(r, mid + 4);
	for (int i = ml; i <= mr; ++i)
		ans = min(ans, t[i].to[y - l] + t[i].back[x - l]);
//		,cout<<i<<"   :"<<t[i].to[y-l]<<"    "<<t[i].back[x-l]<<endl;
	if (max(x, y) < ml)ans = min(ans, ask(x, y, l, ml - 1));
	if (min(x, y) > mr)ans = min(ans, ask(x, y, mr + 1, r));
	return ans;
}

void mysolve()
{

	for (int i = 1; i <= n; ++i)
		{
			int x = i;
			memset(vis, 0, sizeof(vis));
			while (x)
				{
					int tmp = x % 10;
					x /= 10;
					if (!vis[tmp] && tmp)
						{
							vis[tmp] = 1;
							if (i + tmp <= n)to[i].push_back(i + tmp), back[i + tmp].push_back(i);
							if (i - tmp >= 0)to[i].push_back(i - tmp), back[i - tmp].push_back(i);
						}
				}
		}
	solve(0, n);
	int t, x, y;
	cin >> t;
	int ans = 0;
	while (t--)
		{
			cin >> x >> y;
			x ^= ans + 1, y ^= ans + 1;
			ans = ask(x, y, 0, n);
			ans = (ans < inf ? ans : -1);
			cout << ans << endl;
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();

	system("pause");
	return 0;
}
