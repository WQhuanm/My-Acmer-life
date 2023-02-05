#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 30;

int dis[N], head[N << 2], a[N], b[N], cnt[N];
bool vis[N];
int num;
struct node
{
	int next, to, w;
} edge[N << 2];

void add(int u, int v, int w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;
}
void init()
{
	memset(head, 0, sizeof(head));
	memset(cnt, 0, sizeof(cnt));
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	num = 0;
}
//图不一定连通，所以建超级源点约束
bool spfa(int mid)
{
	queue<int>q;
	init();
	add(0, 24, mid);//限制dis[24]不能大于mid
	for (int i = 1; i <= 24; ++i)
		{
			add(i, i - 1, 0), add(i - 1, i, b[i]);
			if (i > 8)add(i, i - 8, -a[i]);
			else add(i, i + 16, mid - a[i]);
		}
	dis[0] = 0;
	q.push(0);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			vis[u] = 0;
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to, w = edge[i].w;
					if (dis[v] > dis[u] + w)
						{
							dis[v] = dis[u] + w;
							if (!vis[v])
								{
									vis[v] = 1;
									q.push(v);
									cnt[v]++;
									if (cnt[v] > 25)return 0;
								}
						}
				}
		}
	if (mid == dis[24])//因为我们是要问这个mid可不可行，已经以mid==s[24]为前提建边，如果你最后跟我说s[24]他他他。。。变了，那肯定不可以呀
		return 1;
	else return 0;
}

int main()
{
	int t, n, x;
	cin >> t;
	while (t--)
		{
			memset(b, 0, sizeof(b));
			for (int i = 1; i <= 24; ++i)cin >> a[i];
			cin >> n;//员工总数
			for (int i = 1; i <= n; ++i)cin >> x, b[x + 1]++;
			int l = 0, r = n;
			int ans = INF;
			while (l <= r)
				{
					int mid = (l + r) >> 1;
					if (spfa(mid))
						{
							ans = mid, r = mid - 1;
						}
					else l = mid + 1;
				}
			if (ans < INF)cout << ans << endl;
			else cout << "No Solution" << endl;
		}
	return 0;
}

