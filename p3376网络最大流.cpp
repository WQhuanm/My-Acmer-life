#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 500;

int n, m, s, t;
int head[N];
int le[N][N];//记录num值，用于快速访问边，le[u][v]即u指向v
bool vis[N];//标记数组
ll dis[N];//记录点的容量
int pre[N];//存储bfs走过路径点（代表的num值），用于回溯修改容量
int num = 1;//一定记得初始化1，不是0
ll ans;//记录结果

struct node
{
	ll w, next, to;
} edge[1000000];

void add(ll u, ll v, ll w)
{
	edge[++num].next = head[u];//加正向边
	edge[num].to = v;
	edge[num].w = w;
	head[u] = num;

	edge[++num].next = head[v];//加反向边
	edge[num].to = u;
	edge[num].w = 0;//边值初始化为0
	head[v] = num;
}

int bfs()
{
	memset(vis, 0, sizeof(vis));//每次清空标记
	queue<int>q;
	q.push(s);
	vis[s] = 1; //起点记得不要忘了在外面标记
	dis[s] = INF;//起点初始赋值极大
	while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = head[x]; i; i = edge[i].next)
				{

					int v = edge[i].to;
					ll w = edge[i].w;
					if (w == 0 || vis[v])continue; //不要忘了排除值为0的边，标记过也跳过
					vis[v] = 1;//记得标记1
					dis[v] = min(dis[x], w);//选取最小值，一直遍历到终点t，最终获得的就是路径上的点中的最小容量
					pre[v] = i;          //记录连接v点的x点的num值，用于回溯
					if (v == t)return 1;//如果v=t，那就是成功到终点了，是一条增广路，返回1
					q.push(v);//否则存入继续遍历
				}
		}
	return 0;//最终不要完了找不到返回0
}

void update()//回溯修改容量
{
	int v = t;//从终点回溯到起点，v记录是哪个点，tmp记录num值
	while (v != s)
		{
			int tmp = pre[v];//获得前面连接v点值的点的num
			edge[tmp].w -= dis[t];//正向边减最小容量（遍历最后就是dis[t])
			edge[tmp ^ 1].w += dis[t];//方向边就增加//注意，这里正反向是相对的
			v = edge[tmp ^ 1].to;//通过反向边回到更前面的点
		}
	ans += dis[t];//不要忘出来了ans累积n减少的容量

}

int main()
{
	cin >> n >> m >> s >> t;
	ll u, v, w;
	for (int i = 1; i <= m; ++i)
		{
			cin >> u >> v >> w;
			if (!le[u][v])
				{
					add(u, v, w);
					le[u][v] = num - 1;
				}
			else
				{
					edge[le[u][v]].w += w;
				}
		}
	while (bfs())//只要找得到增广路，就累积ans
		{
			update();
		}
	cout << ans << endl;
	return 0;
}
