#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 1e6 + 10;
map<double,int>mp,mp1;
int a[N];
struct tree
{
	int l,r;
	double p;
} t[N<<2];
bool cmp(int x,int y)
{
	return x>y;
}
void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r,t[p].p=0;
	if (l==r)return;
	int mid=l+((r-l)>>1);
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
}
void update(int x,int p,double p1)
{
	if (t[p].l==x&&t[p].r==x)
		{
			t[p].p=max(t[p].p,p1);
			return;
		}
	int mid=t[p].l+((t[p].r-t[p].l)>>1);
	if (x<=mid)update(x,p<<1,p1);
	if (x>mid)update(x,p<<1|1,p1);
	t[p].p=max(t[p<<1].p,t[p<<1|1].p);
}

double ask(int l,int r,int p)
{
	if (l<=t[p].l&&t[p].r<=r)return t[p].p;
	int mid=t[p].l+((t[p].r-t[p].l)>>1);
	double ans=0;
	if (l<=mid)
		{
			ans=max(ans,ask(l,r,p<<1));
		}
	if (r>mid)
		{
			ans=max(ans,ask(l,r,p<<1|1));
		}
	return ans;
}

int32_t main()
{
	int n,m,q,r,s,k;
	int maxn=0;
	double p;
	cin>>n>>m>>q;
	build(1,N-1,1);//先建立空树，再每个点补进去，毕竟整棵树不适合建立时一个点一个点带入
	for (int i=1; i<=n; ++i)
		{
			cin>>p>>r;
			if (!mp[p])mp[p]=i,mp1[p]=r;
			else if (mp1[p]<r)//如果已经记录过概率p，那么概率p对应的分数可以更大，更新序号与分数
				{
					mp1[p]=r,mp[p]=i;
				}
			maxn=max(maxn,r);
			update(r,1,p);
		}
	for (int i=1; i<=m; ++i)cin>>a[i];
	sort(a+1,a+1+m,cmp);
	while (q--)
		{
			cin>>s>>k;
			int tmp=max(a[k]-s,1ll);
			if (tmp>maxn)
				{
					cout<<-1<<endl;
				}
			else
				{
					cout<<mp[ask(tmp,maxn,1)]-1<<endl;//输出查询到的区间最大概率对应的最大分数的序号
				}
		}
	return 0;
}
