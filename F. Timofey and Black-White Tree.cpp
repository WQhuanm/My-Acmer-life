#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 100;

int head[N << 1], dis[N],  c[N];
int num;
int n;
int ans;
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

void init()
{
	memset(head, 0, sizeof(head));
	memset(dis, 0x3f, sizeof(dis));
	num = 0;
	ans = INF;
}

void dijksta(int k)
{
	queue<int>q;
	q.push(k);
	ans = min(ans, dis[k]);//当把k设立为黑点，dis[k]表示一个黑点间距离，与ans取min
	dis[k] = 0;//然后我们以这个k黑点为起点，更新其他点到他的距离（如果到k的距离比那个点到已有黑点距离小的话）
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			if (dis[u] + 1 >= ans)continue;//核心剪枝，如果大于目前答案，无需继续深入
			for (int i = head[u]; i; i = edge[i].next)
				{
					int v = edge[i].to;
					if (dis[v] > dis[u] + 1)//到u这个黑点距离小，更新
						{
							dis[v] = dis[u] + 1;
							q.push(v);
						}
				}
		}
}

void mysolve()
{

	cin >> n;
	init();
	int u, v;
	for (int i = 1; i <= n; ++i)cin >> c[i];
	for (int i = 1; i < n; ++i)
		{
			cin >> u >> v;
			add(u, v);
			add(v, u);
		}
	for (int i = 1; i <= n; ++i)//i==1,只是建立c0，铺设所有点都源点的最短距离
		{
			dijksta(c[i]);
			if (i > 1)
				{
					cout << ans;
					if (i == n)cout << endl;
					else cout << ' ';
				}
		}

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
