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
const int N = 2e4 + 10;

int head[N], in[N], dis[N];
int num, cnt, n, m, ans;
struct node
{
	int next, to;
} edge[N];

void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

bool tuopu()
{
	queue<int>q;
	for (int i = 1; i <= n; ++i)if (!in[i])q.push(i);
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			cnt++;
			ans += dis[u];
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					if (--in[v] == 0)
						{
							q.push(v);
							dis[v] = dis[u] + 1;
						}
				}
		}
	if (cnt == n)
		return 1;
	else return 0;
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	while (cin >> n >> m)
		{
			memset(in, 0, sizeof(in));
			memset(head, 0, sizeof(head));
			memset(dis, 0, sizeof(dis));
			num = cnt = ans = 0;
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b;
					add(b, a);
					in[a]++;
				}
			if (tuopu())
				{
					cout << ans + n * 888 << endl;
				}
			else cout << -1 << endl;
		}
	return 0;
}
