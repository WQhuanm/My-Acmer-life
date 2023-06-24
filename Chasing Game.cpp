#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 2e5 + 10;

struct node
{
	int to, next;
} edge[N<<1];

int dep[N],head[N],pre[N][32],lg[N];
int num;

inline void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

void dfs1(int u, int f)
{
	dep[u] = dep[f] + 1;
	pre[u][0] = f;
	for (int i = 1; (1 << i) <= dep[u]; ++i)
		{
			pre[u][i] = pre[pre[u][i - 1]][i - 1];
		}
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v= edge[i].to;
			if (v != f)dfs1(v, u);
		}
}

inline int LCA(int u, int v)
{
	if (dep[v] != dep[u])//不相等时才求，否则出现log2(0)
		{
			if (dep[u] < dep[v])swap(u, v); //始终让u深度大
			int k=lg[dep[u]-dep[v]];
			for (int i = k; ~i; --i)if (dep[pre[u][i]] >= dep[v])u = pre[u][i];
		}
	if (u == v)return u;
	int k = lg[dep[u]];
	for (int i = k; ~i; --i)
		{
			if (pre[u][i] != pre[v][i])
				{
					u = pre[u][i];
					v = pre[v][i];
				}
		}
	return pre[v][0];//儿子的父亲才是LCA
}

int dis(int x,int y)
{
	return abs(dep[x]-dep[y]);
}

void mysolve()
{
	int n,q;
	cin>>n>>q;
	int x,y;
	for(int i=1; i<n; ++i)
		{
			cin>>x>>y;
			add(x,y),add(y,x);
		}
	dfs1(1,0);
	int a,b,c;
	while(q--)
		{
			cin>>b>>c>>a;
			int ab=LCA(a,b),bc=LCA(b,c),ac=LCA(a,c);
			int dac=dis(ac,c)+dis(ac,a),dbc=dis(bc,b)+dis(bc,c);
			if(dac>dbc)
				{
					cout<<dac<<" "<<c<<endl;
				}
			else
				{
					int dab=dis(ab,a)+dis(ab,b);
					int len=dab/2+(dab&1);
					int d=dis(b,bc);
					int ans;
					if(d>=len)
						{
							ans=b;
							int tmp=len;
							int k=lg[dep[b]];
							for (int i = k; ~i; --i)if ((1<<i)<=tmp)ans = pre[ans][i],tmp-=(1<<i);
//							for (int i = k; ~i; --i)if ((1<<i)>=len)ans = pre[ans][i],len-=(1<<i);
						}
					else
						{
							ans=c;
							int tmp=(dep[c]-dep[bc])-(len-d);
							int k=lg[dep[c]];
							for (int i = k; ~i; --i)if ((1<<i)<=tmp)ans = pre[ans][i],tmp-=(1<<i);
						}
					cout<<len<<" "<<ans<<endl;
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	lg[1]=0;//先预处理log
	for(int i=2; i<=N-10; ++i)lg[i]=lg[i>>1]+1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
