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
const int N = 2e6 + 10;

int head[N], in[N], num, h[N];
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
	int n, m, a, b;
	while (cin >> n >> m)
		{
			int k = 0;
			memset(head, 0, sizeof(head));
			memset(in, 0, sizeof(in));
			num = 0;
			for (int i = 1; i <= m; ++i)
				{
					cin >> a >> b;
					add(a, b);
					in[b]++;
				}
			priority_queue<int, vector<int>, greater<int>>q;
			for (int i = 1; i <= n; ++i)if (!in[i])q.push(i);
			while (!q.empty())
				{
					int u = q.top();
					q.pop();
					h[++k] = u;
					for (int i = head[u]; i; i = edge[i].next)
						{
							int v = edge[i].to;
							if (--in[v] == 0)q.push(v);
						}
				}
			for (int i = 1; i <= k ; ++i)
				{
					cout << h[i];
					if (i == k)cout << endl;
					else cout << ' ';
				}
		}

	return 0;
}
