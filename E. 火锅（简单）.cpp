#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const double eps=1e-9;
const int N = 3e5 + 10;
const int mod=998244353;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans=ans*base%mod;
			base=base*base%mod;
			power >>=1;
		}
	return ans;
}

struct tree
{
	int l, r;
	ll sum, add;
} t[N<<2];

inline void pushup(int p)
{
	t[p].sum=(t[ls].sum+t[rs].sum)%mod;
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum=t[p].add=1;//初始化
	if (l == r)
		{
			t[p].sum = 0;
			return;
		}
	build(l, mid, ls),build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p,ll w)
{
	t[p].sum=(t[p].sum*w)%mod;
	t[p].add=(t[p].add*w)%mod;
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)t[p].add = 1;
	if (t[p].add!=1)
		{
			change(ls,t[p].add),change(rs,t[p].add);
			t[p].add = 1;
		}
}

void insert(int x,int p)
{
	if(t[p].l==x&&t[p].r==x)
		{
			t[p].sum=1;
			return;
		}
	lazy(p);
	if(x<=mid)insert(x,ls);
	else insert(x,rs);
	pushup(p);
}

void update(int l, int r, int p, ll z)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change(p,z);
			return;
		}
	lazy(p);
	if (l <= mid)update(l, r, ls, z);
	if (r > mid)update(l, r,rs, z);
	pushup(p);
}

ll ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;
	lazy(p);
	ll ans = 0;
	if (l <= mid)ans=(ans+ ask(l,r,ls))%mod;
	if (r > mid)ans =(ans+ ask(l,r,rs))%mod;
	return ans;
}

void mysolve()
{
	int m,n;
	cin>>m>>n;
	int l,r;
	cin>>l>>r;
	int t;
	string op;
	int cnt=0,ans=0;
	int R=202305;
	build(1,R,1);
	while(n--)
		{
			cin>>op>>t;
			if(op=="add")
				{
					cnt++;
					insert(t,1);
				}
			else
				{
					int res=0;
					if(t-l>=1) res=ask(max(1ll,t-r),t-l,1);
					int inv=fastmi(cnt,mod-2);
					ans=(ans+res*inv)%mod;
					update(1,R,1,(cnt-1)*inv%mod);
					cnt--;
				}
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
