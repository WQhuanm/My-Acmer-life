#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
typedef pair<int,int> pii;
const int N = 110;
const int mod = 998244353;

int cnt;
int a[N];
pii b[N];
ll dis[N];
bool vis[N];

int cost(pii a,pii b)
{
	return abs(a.first-b.first)+abs(a.second-b.second);
}

void mysolve()
{
	int n,d;
	cin>>n>>d;
	for(int i=2; i<n; ++i)cin>>a[i];
	for(int i=1; i<=n; ++i)cin>>b[i].first>>b[i].second;
	priority_queue<pii>q;
	memset(dis,-0x3f,sizeof(dis));
	dis[n]=0;
	q.push({dis[n],n});
	while(!q.empty())
		{
			pii u=q.top();
			q.pop();
			if(vis[u.second])continue;
			vis[u.second]=1;
			for(int i=2; i<n; ++i)if(!vis[i])
					{
						if(dis[i]<dis[u.second]+a[i]-d*cost(b[i],b[u.second]))
							{
								dis[i]=dis[u.second]+a[i]-d*cost(b[i],b[u.second]);
								q.push({dis[i],i});
							}
					}
		}
	ll ans=inf;
	for(int i=2; i<=n; ++i)
		{
			ans=min(ans,cost(b[1],b[i])*d-dis[i]);
		}
	ans=max(ans,0ll);
	cout<<ans<<endl;

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

