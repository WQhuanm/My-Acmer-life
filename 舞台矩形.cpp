#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;         //int型的INF

const int N = 1e5 + 10;
int n;
struct tree
{
	int l,r;
	pll d;//pair的第一个表示高，第二个表示低
} t[N<<2];
pll a[N],b[N];
void build (int l,int r,int p)
{
	t[p].l=l,t[p].r=r;
	if (l==r)
		{
			t[p].d.first=t[p].d.second=a[l].second;
			return;
		}
	int mid=l+((r-l)>>1);
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	t[p].d.first=max(t[p<<1].d.first,t[p<<1|1].d.first);
	t[p].d.second=min(t[p<<1].d.second,t[p<<1|1].d.second);
}

pll ask(int l,int r,int p)//pair返回区间最高最低
{
	if (l<=t[p].l&&t[p].r<=r)return t[p].d;
	pll tmp= {-INF,INF};
	int mid=t[p].l+((t[p].r-t[p].l)>>1);
	if (l<=mid)	tmp.first=max(tmp.first,ask(l,r,p<<1).first),tmp.second=min(tmp.second,ask(l,r,p<<1).second);
	if (r>mid)	tmp.first=max(tmp.first,ask(l,r,p<<1|1).first),tmp.second=min(tmp.second,ask(l,r,p<<1|1).second);
	return tmp;
}

pll find(int x1,int x2)//通过b数组的x值查询对应的排序后的a数组位置
{
	int l=1,r=n,ans1,ans2;
	while (l<=r)
		{
			int mid=l+((r-l)>>1);
			if (a[mid].first>=x1)ans1=mid,r=mid-1;
			else  l=mid+1;
		}
	l=1,r=n;
	while (l<=r)
		{
			int mid=l+((r-l)>>1);
			if (a[mid].first<=x2)ans2=mid,l=mid+1;
			else r=mid-1;
		}
	return {ans1,ans2};
}
int32_t main()
{

	cin>>n;
	for (int i=1; i<=n; ++i)cin>>a[i].first>>a[i].second,b[i]=a[i];
	sort(a+1,a+1+n);
	build(1,n,1);
	int q;
	cin>>q;
	int A,B;
	while (q--)
		{
			cin>>A>>B;
			int ans=b[B].first-b[A].first;
			if (ans>0)//你右-左坐标差为正数才执行，否则为0
				{
					pll t=find(b[A].first,b[B].first);
					pll	tmp=ask(t.first,t.second,1);
					ans*=tmp.first-tmp.second;
				}
			else ans=0;
			cout<<ans<<endl;
		}
	return 0;
}

