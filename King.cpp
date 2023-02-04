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
const int N = 1e2 + 10;

int s[N], head[N], cnt[N];
bool vis[N], flag;
struct node
{
	int next, to, w;
} edge[N];
int num;
int n, m;

void init()
{
	memset(head, 0, sizeof(head));
	memset(s, 0x3f, sizeof(s));
	memset(cnt, 0, sizeof(cnt));
	memset(vis, 0, sizeof(vis));
	num = 0;
}

void add(int u, int v, int w)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;
}
//图不一定连通，所以建超级源点约束
bool spfa()
{
	queue<int>q;
	s[n + 1] = 0;
	q.push(n + 1);
	while (!q.empty())
		{
			int u = q.front();
			cnt[u]++;
			if (cnt[u] > n + 1)
				{
					return 0;
				}
			q.pop();
			vis[u] = 0;
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to, w = edge[i].w;
					if (s[v] > s[u] + w)
						{
							s[v] = s[u] + w;
							if (!vis[v])vis[v] = 1, q.push(v);
						}
				}
		}
	return 1;
}

int main()
{
	string b;
	while (cin >> n && n)
		{
			init();
			cin >> m;
			int x, n1, k;
			for (int i = 1; i <= m; ++i)
				{
					cin >> x >> n1 >> b >> k;
					if (b[0] == 'g')
						{
							add(x + n1, x - 1, -k - 1);
						}
					else if (b[0] == 'l')
						{
							add(x - 1, x + n1, k - 1);
						}
				}
			for (int i = 0; i <= n; ++i)add(n + 1, i, 0);
			flag = spfa();
			if (flag)cout << "lamentable kingdom" << endl;
			else
				{
					cout << "successful conspiracy" << endl;
				}
		}

	return 0;
}

