#define _CRT_SECURE_NO_WARNINGS 1
#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

struct node
{
	ll to, next;
} edge[N << 1]; //无向边记录俩个方向，记得开边界俩倍

ll dep[N];
ll pre[N][32];//dep记录当前点的深度，默认根节点深度（起始深度为1），pre[u][i]表示u的二进制（2^i)祖先，如pre[u][0]就是u的2^0祖先，即爸爸，用这个方法倍增，就可以不用一步一步慢慢走，时间从n变为logn

ll head[N];
ll num;

ll point[N];
ll ans;

void add(ll f, ll t)//链式向前星加边
{
	edge[++num].next = head[f];
	edge[num].to = t;
	head[f] = num;
}

void dfs1(ll u, ll fa)//建树第一步，dfs1遍历从头到尾的点，依靠前面已经建边的关系，建立好各个点的深度
{
	//u为当前节点，fa为该节点的父亲
	dep[u] = dep[fa] + 1;//这就是为什么从头开始，这样深度就由浅到深可以一代一代继承
	pre[u][0] = fa;//显然把父子关系继承到pre祖先数组
	for (int i = 1; (1 << i) < dep[u]; ++i)//二进制倍增，从2，4，8....填完祖先倍增关系
		{
			pre[u][i] = pre[pre[u][i - 1]][i - 1];//显然，u的2^i祖先等于（u的2^(i-1)祖先）的2^(i-1)祖先，如果不超过u的深度，就可以这么干
		}//（注意，每次走的步数都是从u这个点走，走2^i步，起点没有变）
	for (int i = head[u]; i; i = edge[i].next)
		{
			ll h = edge[i].to;
			if (h != fa)dfs1(h, u);//与u有联系的边，只要不是fa，那就是他的儿子，那就往深处dfs
		}
}

ll LCA(ll u, ll v)
{
	if (dep[u] > dep[v])swap(u, v); //始终让v深度大
	ll k = log2(dep[v] - dep[u]); //我们是倍增跑，所以n距离，只需要log2（n）
	for (int i = k; i >= 0; --i)
		{
			if (dep[pre[v][i]] >= dep[u])v = pre[v][i]; //只要v的深度还大于u，我们一定可以移动到俩者深度一样（因为二进制可以表示任何数）
		}
	//出来u等于v，但是有可能v就是fca（u==v的话)
	if (u == v)return u; //是最近返回LCA
	k = log2(dep[v]); //不是,还是按深度走log2n步
	for (int i = k; i >= 0; --i)
		{
			if (pre[u][i] != pre[v][i]) //注意，我们是只有走下去不是祖先才走，因为你可能一步太大，走到LCA前面的公共点
				{
					u = pre[u][i];
					v = pre[v][i];
				}
		}
	//这样我们出来刚好到LCA的儿子那里
	return pre[v][0];//儿子的父亲才是LCA
}
void dfs(ll u, ll fa)
{
	for (int i = head[u]; i; i = edge[i].next)
		{
			ll h = edge[i].to;
			if (h != fa)
				{
					dfs(h, u);
					//是遍历回来（已经累加过子代的值，祖先才加）
					point[u] += point[h];
				}
		}
	ans = max(ans, point[u]);
}

int main()
{
	ll n, k;
	cin >> n >> k;
	ll f, t;
	for (int i = 1; i <= n - 1; ++i)
		{
			cin >> f >> t;
			add(f, t);
			add(t, f);
		}
	dfs1(1, 0);
	for (int i = 1; i <= k; ++i)
		{
			cin >> f >> t;
			ll lca = LCA(f, t);
			point[f]++;
			point[t]++;
			point[lca]--;
			point[pre[lca][0]]--;
		}
	dfs(1, 0); //这个dfs求ans
	cout << ans << endl;
}
