#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 2e5 + 10;

int t[N],a[N];
int n,q;
void update(int x,int w)
{
	t[x]=a[x]=w;//修改时该点也要修改
	while(x<=n)//遍历x及其所有树上祖先进行修改
		{
			int lx=x&-x;//lowbit(x)
			for(int i=1; i<lx; i<<=1)//遍历[x-lowbit[x]+1,x],即小于lowbit(x)的位
				{
					t[x]=max(t[x],t[x-i]);
				}
			x+=x&-x;
		}
}

int ask(int l,int r)
{
	int ans=a[r];
	while(l<=r)
		{
			int lx=r-(r&-r)+1;
			if(lx>=l)ans=max(ans,t[r]),r=lx-1;//查询时，如果[x-lowbit[x]+1,x]在范围内，直接获取，否则，取出a[x]，x--
			else ans=max(ans,a[r]),r--;
		}
	return ans;
}

void mysolve()
{

	while(cin>>n>>q)
		{
			for(int i=1; i<=n; ++i)cin>>a[i],update(i,a[i]);
			int x,y;
			char c;
			while(q--)
				{
					cin>>c>>x>>y;
					if(c=='Q')cout<<ask(x,y)<<endl;
					else update(x,y);
				}
		}
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
