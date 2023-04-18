#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;
struct tree
{
	int l,r;
	int minn,sum;
} t[N<<2];
int a[N];
void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r,t[p].minn=INF,t[p].sum=0;
	if(l==r)
		{
			t[p].minn=t[p].sum=a[l];
			return;
		}
	int mid=l+((r-l)>>1);
	build(l,mid,p<<1);
	build(mid+1,r,p<<1|1);
	t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn);
	t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}

void update(int x,int p,int w)
{
	if(t[p].l==x&&t[p].r==x)
		{
			t[p].minn=t[p].sum=w;
			return;
		}
	int mid=t[p].l+((t[p].r-t[p].l)>>1);
	if(x<=mid)update(x,p<<1,w);
	else update(x,p<<1|1,w);
	t[p].minn=min(t[p<<1].minn,t[p<<1|1].minn);
	t[p].sum=t[p<<1].sum+t[p<<1|1].sum;
}
int asksum(int l,int r,int p)
{
	if(l<=t[p].l&&t[p].r<=r)return t[p].sum;
	int ans=0;
	int mid=t[p].l+((t[p].r-t[p].l)>>1);
	if(l<=mid)ans+=asksum(l,r,p<<1);
	if(r>mid)ans+=asksum(l,r,p<<1|1);
	return ans;
}

int askmin(int l,int r,int p)
{
	if(l<=t[p].l&&t[p].r<=r)return t[p].minn;
	int ans=INF;
	int mid=t[p].l+((t[p].r-t[p].l)>>1);
	if(l<=mid)ans=min(ans,askmin(l,r,p<<1));
	if(r>mid)ans=min(ans,askmin(l,r,p<<1|1));
	return ans;
}

void mysolve()
{
	int n,q,op,x,y;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i];
	build(1,n,1);
	cin>>q;
	while(q--)
		{
			cin>>op>>x>>y;
			if(op==1)
				{
					swap(a[x],a[y]);
					update(x,1,a[x]);
					update(y,1,a[y]);
				}
			else
				{
					int minn=n+1;
					if(x>1)
						minn=min(minn,askmin(1,x-1,1));
					if(y<n)
						minn=min(minn,askmin(y+1,n,1));
					int ans=asksum(x,y,1);
					ans*=minn;
					cout<<ans<<endl;
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
