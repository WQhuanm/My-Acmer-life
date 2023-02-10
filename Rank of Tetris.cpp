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
const int N = 1e5 + 10;

int head[N << 1], in[N], fa[N], a[N], b[N];
char s[N];
bool vis[N];
int num, n, m, ans;
struct node
{
	int next, to;
} edge[N << 1];

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

int find(int x)
{
	if (fa[x] != x)fa[x] = find(fa[x]);
	return fa[x];
}

int tuopu()
{
	queue<int>q;
	bool flag = 0;
	for (int i = 0; i < n; ++i)if (!in[i] && find(i) == i)q.push(i);
	while (!q.empty())
		{
			if ((int)q.size() > 1)flag = 1;
			int u = q.front();
			q.pop();
			ans--;
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					//	if (u == v)return -1;
					//	if (vis[v])return -1;
					if (--in[v] == 0)q.push(v);
				}
		}
	if (ans > 0)return -1;
	if (flag)return 0;
	return 1;
}

int main()
{
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while (cin >> n >> m)
		{
			memset(in, 0, sizeof(in));
			memset(head, 0, sizeof(head));
			//	memset(vis, 0, sizeof(vis));
			num = 0;
			ans = n;
			for (int i = 0; i < n; ++i)fa[i] = i;
			for (int i = 1; i <= m; ++i)
				{
					cin >> a[i] >> s[i] >> b[i];
					if (s[i] == '=')
						{
							int x = find(a[i]), y = find(b[i]);
							if (x != y)ans--, fa[x] = y;
						}
				}
			for (int i = 1; i <= m; ++i)if (s[i] != '=')
					{
						int x = find(a[i]), y = find(b[i]);
						if (s[i] == '>')
							{
								add(x, y);
								in[y]++;
							}
						else if (s[i] == '<')add(y, x), in[x]++;
					}
			int k = tuopu();
			if (k == 1)cout << "OK" << endl;
			else if (k == -1)cout << "CONFLICT" << endl;
			else if (k == 0)cout << "UNCERTAIN" << endl;
		}

	return 0;
}
