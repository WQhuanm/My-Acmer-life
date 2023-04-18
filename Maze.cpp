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
double f1[N],f2[N],f3[N],k[N],e[N];
vector<int>edge[N];

void dfs(int u,int f)
{
	double cnt=0;
	if(u!=1)cnt++;
	for(auto v:edge[u])if(v!=f)
			{
				dfs(v,u);
				cnt++;
				f1[u]+=f1[v],f2[u]+=f2[v],f3[u]+=f3[v];
			}
	double y=1-k[u]-e[u],p=1.0;
	p=(1-f2[u]*y/cnt);
	f1[u]=(f1[u]*y/cnt+k[u])/p;
	f2[u]=(y/cnt)/p;
	f3[u]=(f3[u]/cnt+1)*y/p;
}
void mysolve()
{
	int n,x,y;
	cin>>n;
	for(int i=1; i<=n; ++i)f1[i]=f2[i]=f3[i]=0.0,edge[i].clear();
	for(int i=1; i<n; ++i)scanf("%lld %lld",&x,&y),edge[x].push_back(y),edge[y].push_back(x);
	for(int i=1; i<=n; ++i)scanf("%lf %lf",&k[i],&e[i]),k[i]/=100.0,e[i]/=100.0;
	dfs(1,0);
	if(fabs(1-f1[1])<1e-9)cout<<"impossible"<<endl;
	else
		{
			double ans=f3[1]/(1-f1[1]);
			printf("%.6lf\n",ans);
		}

}

int32_t main()
{
	//    std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	int tt=1;
	while (t--)
		{
			printf("Case %lld: ",tt++);
			mysolve();
		}
	system("pause");
	return 0;
}
