#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e5 + 20;
const int mod=998244353;
int a[N];
int n,q;
#define ls p<<1
#define rs p<<1|1
#define mid (t[p].l+((t[p].r-t[p].l)>>1))
ll pre[N],dev[N],tmp[4][4];
struct tree
{
	int l,r;
	int ld,rd;
	int add,cnt;
	int sum[4][4];
} t[N<<2];

inline ll fastmi(ll base,ll power)
{
	ll ans=1;
	while(power)
		{
			if(power&1)ans=ans*base%mod;
			base=base*base%mod;
			power>>=1;
		}
	return ans;
}

inline void pushup(int p)
{
	for(int i=0; i<4; ++i)for(int j=0; j<4; ++j)t[p].sum[i][j]=t[ls].sum[i][j]+t[rs].sum[i][j];
	t[p].sum[t[ls].rd][t[rs].ld]++;
	t[p].ld=t[ls].ld,t[p].rd=t[rs].rd;
	t[p].cnt=t[ls].cnt+t[rs].cnt;
	if(t[ls].rd>=t[rs].ld)t[p].cnt++;
}

void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r;
	if(t[p].l==t[p].r)
		{
			t[p].ld=t[p].rd=a[l];
			return;
		}
	build(l,mid,ls),build(mid+1,r,rs);
	pushup(p);
}

inline void change(int p,int w)
{
	for(int i=0; i<4; ++i)for(int j=0; j<4; ++j)tmp[i][j]=t[p].sum[i][j];
	for(int i=0; i<4; ++i)for(int j=0; j<4; ++j)t[p].sum[(i+w)%4][(j+w)%4]=tmp[i][j];
	t[p].ld=(t[p].ld+w)%4,t[p].rd=(t[p].rd+w)%4;
	t[p].cnt=0;
	for(int i=0; i<4; ++i)for(int j=i; ~j; --j)t[p].cnt+=t[p].sum[i][j];
	t[p].add+=w;
}

inline void lazy(int p)
{
	if(t[p].l==t[p].r)t[p].add=0;
	if(t[p].add)
		{
			change(ls,t[p].add),change(rs,t[p].add);
			t[p].add=0;
		}
}

void update(int l,int r,int p)
{
	if(l<=t[p].l&&t[p].r<=r)
		{
			change(p,1);
			return;
		}
	lazy(p);
	if(mid>=l)update(l,r,ls);
	if(mid<r)update(l,r,rs);
	pushup(p);
}

int ask(int l,int r,int p)
{
	if(l<=t[p].l&&t[p].r<=r)return t[p].cnt;
	int ans=0;
	lazy(p);
	if(mid>=l)ans+=ask(l,r,ls);
	if(mid<r)ans+=ask(l,r,rs);
	if(l<=mid&&mid<r)ans+=(t[ls].rd>=t[rs].ld);
	return ans;
}

inline ll C(int n,int m)
{
	if(m>n||m<0||n<0)return 0;
	return 1ll*pre[n]*dev[m]%mod*dev[n-m]%mod;
}

void mysolve()
{
	cin>>n>>q;
	string s;
	cin>>s;
	for(int i=0; i<n; ++i)a[i+1]=s[i]-'A';
	build(1,n,1);
	int l,r,k,op;
	while(q--)
		{
			cin>>op>>l>>r;
			if(op==1)update(l,r,1);
			else
				{
					cin>>k;
					int cnt=ask(l,r,1);
					cout<<C(r-l-cnt,k-1-cnt)<<endl;
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	pre[0]=1;
	int nx=1e5;
	for(int i=1; i<=nx; ++i)pre[i]=pre[i-1]*i%mod;
	dev[nx]=fastmi(pre[nx],mod-2)%mod;
	for(int i=nx-1; ~i; --i)dev[i]=dev[i+1]*(i+1)%mod;
	mysolve();
	system("pause");
	return 0;
}

