#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
const int N = 1e4 + 10;

int vis[N],in[N],book[N];
int a,b;
int getpin(int x)
{
	int ans=0;
	while (x)
		{
			ans+=(x%10)*(x%10);
			x/=10;
		}
	return ans;
}

int dfs(int x)
{
	if (vis[x])return vis[x];//-1表示不是幸福数，1表示是，0表示还未处理
	int v=getpin(x);
	vis[x]=-1;//初始设置为不是，防止循环
	vis[x]=dfs(v);
	if (vis[x]==1)//如果回来检测到他是幸福数，显然v依附x（v由x得到)
		{
			if (x<=b&&x>=a)//如果x在区间内，显然v在区间内有依附，不独立
				book[v]=1;//标记为1就是不独立
			in[x]=in[v]+1;//in表示包括x自己在内的依附与它的数，显然，依附于v的数也依附于x
		}
	return vis[x];
}

bool judsu(int x)//埃氏筛
{
	if (x==1||x==2||x==4)return 0;
	if (x==3||x==5)return 1;
	if (x%6!=1&&x%6!=5)return 0;
	for (int i=5; i*i<=x; i+=6)if (x%i==0||x%(i+2)==0)return 0;
	return 1;
}

void mysolve()
{
	cin>>a>>b;
	vis[1]=in[1]=1;
	for (int i=2; i<=1e4; ++i)
		{
			if (vis[i])continue;
			dfs(i);
		}
	bool flag=0;
	for (int i=a; i<=b; ++i)
		{
			if (vis[i]==1&&!book[i])//是幸福数且独立
				{
					flag=1;
					int ans=in[i]-1;
					if (judsu(i))ans*=2;
					cout<<i<<" "<<ans<<endl;
				}
		}
	if (!flag)cout<<"SAD"<<endl;

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
