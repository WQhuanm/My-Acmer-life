#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f

typedef pair<int, int> pii;

const int N = 3e5 + 10;
const int mod = 998244353;

#define ls p<<1
#define rs p<<1|1
#define mid  (t[p].l + ((t[p].r - t[p].l) >> 1))

struct tree
{
	int l, r;
	ll sum, add;
} t[N<<2];
int a[N];

inline void pushup(int p)
{
	t[p].sum=(t[ls].sum+t[rs].sum);
}

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r;
	t[p].sum=0,t[p].add=-1;//初始化
	if (l == r)
		{
			t[p].sum = a[l]==1;
			return;
		}
	build(l, mid, ls),build(mid + 1, r, rs);
	pushup(p);
}

inline void change(int p,ll w)
{
	t[p].sum=(w*(t[p].r-t[p].l+1));
	t[p].add=(w);
}

inline void lazy(int p)
{
	if (t[p].l == t[p].r)t[p].add = -1;
	if (t[p].add!=-1)
		{
			change(ls,t[p].add),change(rs,t[p].add);
			t[p].add = -1;
		}
}

void update(int l, int r, int p, ll w)
{
	if (l <= t[p].l && t[p].r <= r)
		{
			change(p,w);
			return;
		}
	lazy(p);
	if (l <= mid)update(l, r, ls, w);
	if (r > mid)update(l, r,rs, w);
	pushup(p);
}

ll ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;
	lazy(p);
	ll ans = 0;
	if (l <= mid)ans=(ans+ ask(l,r,ls));
	if (r > mid)ans =(ans+ ask(l,r,rs));
	return ans;
}

pii b[N];
void mysolve()
{
	string s,f;
	int n,q;
	cin>>n>>q>>s>>f;
	s="$"+s,f="$"+f;
	for(int i=1; i<(int)f.size(); ++i)a[i]=f[i]-'0';
	build(1,n,1);
	for(int i=1; i<=q; ++i)cin>>b[i].first>>b[i].second;
	for(int i=q; i; --i)
		{
			int l=b[i].first,r=b[i].second;
			int cnt=ask(l,r,1);
			int len=r-l+1;
			if(cnt<=(len-1)/2)
				{
					update(l,r,1,0);
				}
			else if(cnt>=len-(len-1)/2)
				{
					update(l,r,1,1);
				}
			else
				{
					cout<<"NO"<<endl;
					return;
				}
		}
	for(int i=1; i<=n; ++i)if(s[i]-'0'!=(ask(i,i,1)==1))
			{
				cout<<"NO"<<endl;
				return;
			}
	cout<<"YES"<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

inline int read(int &x)
{
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9')ch = getchar();
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + ch - '0';
			ch = getchar();
		}
	return x;
}
