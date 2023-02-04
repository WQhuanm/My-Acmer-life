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
const int N = 1e3 + 10;

int head[N], dis[N], a[N], cnt[N];
bool vis[N];
int num, n;
struct node
{
	int next, to, w;
} edge[N * N];

void init()
{

}

void add(int u, int v, int w)
{
	edge[++num].next = head[u];
	edge[num].w = w;
	edge[num].to = v;
	head[u] = num;
}

bool spfa()
{
	queue<int>q;
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	memset(dis, 0x3f, sizeof(dis));
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
									vis[v] = 1, q.push(v);
									cnt[v]++;
									if (cnt[v] > n + 1)return 0;
								}

						}
				}
		}
	return 1;
}

int main()
{
	//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string b;
	int x, y;
	int t = 0;
	while (cin >> n && n)
		{
			memset(head, 0, sizeof(head));
			num = 0;
			for (int i = 1; i <= n; ++i)cin >> a[i], add(0, i, -a[i]);
			while (cin >> b)
				{
					if (b[0] == '#')break;
					cin >> x >> y;
					if (b[0] == 'F' && b[2] == 'S')
						{
							add(x, y, a[x]);
						}
					else if (b[0] == 'F' && b[2] == 'F')
						{
							add(x, y, a[x] - a[y]);
						}
					else if (b[0] == 'S' && b[2] == 'F')
						{
							add(x, y, -a[y]);
						}
					else if (b[0] == 'S' && b[2] == 'S')
						{
							add(x, y, 0);
						}
				}

			printf("Case %d:\n", ++t);
			if (spfa())
				{
					int minn = INF;
					for (int i = 1; i <= n; ++i)minn = min(dis[i], minn);
					for (int i = 1; i <= n; ++i)cout << i << ' ' << dis[i] - minn << endl;
				}
			else cout << "impossible" << endl;
			cout << endl;
		}

	return 0;
}

