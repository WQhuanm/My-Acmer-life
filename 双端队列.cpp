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
const int N = 2e6 + 10;

#define mid (t[p].l+((t[p].r-t[p].l)>>1))
#define ls p<<1
#define rs p<<1|1
struct tree
{
	int l,r;
	int sum;
} t[N<<2];
int a[N];

void build(int l,int r,int p)
{
	t[p].l=l,t[p].r=r,t[p].sum=0;
	if(l==r)return;
	build(l,mid,ls);
	build(mid+1,r,rs);
}

void update(int x,int p,int val)
{
	if(t[p].l==t[p].r&&t[p].l==x)
		{
			t[p].sum+=val;//维护当前区间存在几个实际存在未被删除的数
			return;
		}
	if(mid>=x)update(x,ls,val);
	else update(x,rs,val);
	t[p].sum=t[ls].sum+t[rs].sum;
}

int ask(int x,int p,int sum)
{
	if(t[p].l==t[p].r)return t[p].l;
	if(sum+t[ls].sum>=x)return ask(x,ls,sum);
	else return ask(x,rs,sum+t[ls].sum);
}

void mysolve()
{
	int n,x;
	map<int,vector<int>>mp;
	cin>>n;
	build(1,2*n,1);
	int l=n,r=n+1;
	char op;
	while(n--)
		{
			cin>>op>>x;
			if(op=='F')
				{
					update(l,1,1);
					a[l]=x;
					mp[x].push_back(l--);
				}
			else if(op=='B')
				{
					update(r,1,1);
					a[r]=x;
					mp[x].push_back(r++);
				}
			else if(op=='D')
				{
					if(mp.count(x)&&mp[x].size()>0)//每次访问x最后一次插入的位置
						{
							update(mp[x].back(),1,-1);
							mp[x].pop_back();
						}
				}
			else
				{
					if(t[1].sum>=x)cout<<a[ask(x,1,0)]<<endl;
					else cout<<-1<<endl;
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
