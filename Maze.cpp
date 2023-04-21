#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 1e4 + 10;
double f1[N],f2[N],f3[N];
vector<int>edge[N];
double p1[N],p2[N];

void dfs(int u,int f)
{
	double cnt=0.0,son=0.0;//都设置为浮点数，cnt为整形会wa
	if(u!=1)cnt++;//加一个父节点
	for(auto v:edge[u])if(v!=f)
	{
		dfs(v,u);
		f1[u]+=f1[v],son+=f2[v],f3[u]+=f3[v];//继承子代们的各项系数
		cnt++;
	}
	double y=1-p1[u]-p2[u],p=1.0;
	if(cnt>0.0)p=1-y*son/cnt;
	f1[u]=(y*f1[u]/cnt+p1[u])/p;
	if(cnt>0.0)f2[u]=y/cnt/p;
	f3[u]=y*(f3[u]/cnt+1)/p;
}
int tt=0;
void mysolve()
{
	int n,x,y;
	cin>>n;
	for(int i=1; i<=n; ++i)edge[i].clear(),f1[i]=f2[i]=f3[i]=0.0;
	for(int i=1; i<n; ++i)scanf("%d %d",&x,&y),edge[x].push_back(y),edge[y].push_back(x);
	for(int i=1; i<=n; ++i)scanf("%lf %lf",&p1[i],&p2[i]),p1[i]/=100.0,p2[i]/=100.0;
	dfs(1,0);
	cout<<"Case "<<++tt<<": ";
	if(fabs(f1[1]-1.0)<1e-9)
	{
		cout<<"impossible"<<endl;
	}
	else
	{
		double ans=f3[1]/(1-f1[1]);
		printf("%.6lf\n",ans);
	}
}

int32_t main()
{
	ll t=1;
	cin >> t;
	while (t--)
	{
		mysolve();
	}
	system("pause");
	return 0;
}
