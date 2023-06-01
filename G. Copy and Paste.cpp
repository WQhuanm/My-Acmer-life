#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define inf 0x3f3f3f
const int N = 1e5 + 10;

struct node
{
	int next, to;
} edge[N << 1];

int num, cnt;
int head[N << 1], sz[N], dep[N], fa[N], son[N], top[N], idx[N];
int dp[N];
void add(int u, int v)
{
	edge[++num].next = head[u];
	edge[num].to = v;
	head[u] = num;
}

//---------以下是线段树代码-------//
#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll val;//维护最大值
	int cnt,last,dot;//dot为前缀长度
	int len;//len为last+dot,维护最小值
} t[N<<2];

bool vis[N];
int a[N];

void pushup(int p)
{
	t[p].val=min(t[ls].val,t[rs].val);
	if(t[ls].len<t[rs].len)t[p].dot=t[ls].dot,t[p].len=t[ls].len;
	else if(t[ls].len==t[rs].len)t[p].len=t[ls].len,t[p].dot=min(t[ls].dot,t[rs].dot);
	else t[p].dot=t[rs].dot,t[p].len=t[rs].len;
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].val=inf,t[p].cnt=0;//初始化
	if (l == r)
		{
			t[p].dot=a[l];
			t[p].last=a[l]-1;

			if(t[p].dot==0)t[p].last=inf;
			t[p].len=t[p].last+a[l];
			return;
		}
	build(l, mid, ls),build(mid + 1, r, rs);
	pushup(p);
}

void update(int l, int r, int p, int w)
{
	if (l <= t[p].l && t[p].r <= r&&t[p].r==t[p].l)
		{
			t[p].last=w,t[p].cnt++;
			t[p].len=t[p].last+t[p].dot;
			t[p].val=dp[a[l]-1]+1-(a[l]-1)-t[p].cnt*(a[l]-1);
			return;
		}
	if (l <= mid)update(l, r, ls, w);
	if (r > mid)update(l, r,rs, w);
	pushup(p);
}

int ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].val;
	int ans = inf;
	if (l <= mid)ans=min(ans,ask(l,r,ls));
	if (r > mid)ans =min(ans, ask(l,r,rs));
	return ans;
}

int askpoint(int l,int r,int p,int w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			if(t[p].len<=w)return t[p].dot;
			else return 0;
		}
	if (l <= mid)
		{
			int tmp=askpoint(l,r,ls,w);
			if(tmp)return tmp;
		}
	if(r>mid)
		{
			int tmp=askpoint(l,r,rs,w);
			if(tmp)return tmp;
		}
	return 0;
}

//------以上是线段树代码------//

void dfs1(int u, int f)//建树
{
	fa[u] = f;
	vis[u]=1;
	dep[u] = dep[f] + 1;
	sz[u] = 1, son[u] = idx[u] = 0;//初始化
	int mx = -1;
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (v == f||vis[v])continue;
			dfs1(v, u);
			sz[u] =(sz[u]+sz[v]);
			if (sz[v] > mx)mx = sz[v], son[u] = v;//更新重儿子
		}
}

void dfs2(int u, int topfa)
{
	top[u] = topfa;//记录链顶点
	idx[u] = ++cnt;
	a[cnt] =u;
	if (!son[u])return;//没儿子
	dfs2(son[u], topfa);//重儿子优先编号
	for (int i = head[u]; i; i = edge[i].next)
		{
			int v = edge[i].to;
			if (!idx[v])dfs2(v, v);//v是自己轻链的顶点
		}
}

void treeadd(int x, int y, int w)
{
	update(idx[x], idx[y], 1, w);
}

int treeask(int x, int y)//询问最小val
{
	int ans = inf;
	while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y);
			ans = min(ans, ask(idx[top[x]], idx[x], 1));
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	ans = min(ans, ask(idx[x], idx[y], 1));
	return ans;
}

int  treeaskpoint(int x, int y,int w)//询问是否存在需要更新的点
{
	while (top[x] != top[y])
		{
			if (dep[top[x]] < dep[top[y]])swap(x, y);
			int tmp= askpoint(idx[top[x]], idx[x], 1,w);
			if(tmp!=0)return tmp;
			x = fa[top[x]];
		}
	if (dep[x] > dep[y])swap(x, y);
	int tmp= askpoint(idx[x], idx[y], 1,w);
	return tmp;
}

int p[N];
void mysolve()
{
	string s;
	cin >> s;
	int n=(int)s.size();
	p[0] = 0;//只有一个字符，当然为0
	for (int i = 1; i < n; ++i)//从2个字符以上开始（i=1开始）
		{
			int j = p[i - 1];//每次都先取上一次i-1长度的最长前缀长度，接下来判断是否s[i]==s[j],因为下标从0开始，j是长度，所以j刚好就是最长前缀的下一位，如果判断两者相同，不用走while，直接j+1
			while (j  && s[i] != s[j])j = p[j-1];//如果不相等，范围缩小为p[j-1],j-1是比原来前缀少1，p[j-1]就是在这个前缀范围找前缀，如果为0，就是没有前缀，所以为0跳出（用j>0限制）
			if (s[i] == s[j])++j;//如果出来（没进去while也一样）相等，说明下一位相同，j+1
			p[i] = j;//存储p[i+1]
			if(p[i])add(p[p[i]-1],p[i]);
		}
	dep[0]=-1;
	cnt=0;
	dfs1(0, 0);//建树
	dfs2(0, 0);//从根节点开始重新编号
	build(1,cnt, 1);
	dp[0]=1;
	for(int i=1; i<n; ++i)
		{
			dp[i]=dp[i-1]+1;
			while(1)//询问需要更新的点，这个操作最多执行nlogn次
				{
					int tmp=0;
					if(p[i])tmp=treeaskpoint(0,p[i],i);
					if(tmp)treeadd(tmp,tmp,i);
					else break;
				}
			if(p[i]>0)dp[i]=min(dp[i],i+treeask(0,p[i]));
		}
	cout<<dp[n-1]<<endl;
}

int32_t main()
{
	mysolve();
	system("pause");
	return 0;
}

