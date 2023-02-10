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
const int N = 2e5 + 10;

int head[N], in[N], a[N];
int num;
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

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t, n, m, u1, v1;
	cin >> t;
	while (t--)
		{
			priority_queue<int>q;
			memset(head, 0, sizeof(head));
			memset(in, 0, sizeof(in));
			num = 0;
			int k = 0;
			cin >> n >> m;
			for (int i = 1; i <= m; ++i)
				{
					cin >> v1 >> u1;///////////////
					add(u1, v1);
					in[v1]++;
				}
			for (int i = 1; i <= n; ++i)
				{
					if (!in[i])q.push(i);
				}
			while (!q.empty())
				{
					int u = q.top();
					q.pop();
					a[++k] = u;
					for (int i = head[u]; i; i = edge[i].next)
						{
							int v = edge[i].to;
							if ((--in[v] ) == 0)//////////
								{
									q.push(v);
								}
						}
				}
			for (int i = k; i >= 1; --i)
				{
					cout << a[i];
					if (i == 1)cout << endl;
					else cout << ' ';
				}

		}
	return 0;
}
