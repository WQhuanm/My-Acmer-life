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
int in[N];
struct node
{
	int x,y,id;//x,y记录运算符的左右值，id表示操作
	double w;//w表示当前函数值
} b[N];
double dm[N];//表示当前节点导数值

double dfs(int u)//求函数
{
	if (b[u].w<INF)return b[u].w;
	else if (b[u].id==1)b[u].w=dfs(b[u].x)+dfs(b[u].y);
	else if (b[u].id==2)b[u].w=dfs(b[u].x)-dfs(b[u].y);
	else if (b[u].id==3)b[u].w=dfs(b[u].x)*dfs(b[u].y);
	else if (b[u].id==4)b[u].w=exp(dfs(b[u].x));
	else if (b[u].id==5)b[u].w=log(dfs(b[u].x));
	else if (b[u].id==6)b[u].w=sin(dfs(b[u].x));
	return b[u].w;
}

double dfs1(int u,int i)//求导数，就是导数公式
{
	if (dm[u]!=INF)return dm[u];
	else if (b[u].id==0)return dm[u]=(u==i?1:0);
	else if (b[u].id==1)dm[u]=dfs1(b[u].x,i)+dfs1(b[u].y,i);
	else if (b[u].id==2)dm[u]=dfs1(b[u].x,i)-dfs1(b[u].y,i);
	else if (b[u].id==3)dm[u]=dfs1(b[u].x,i)*b[b[u].y].w+dfs1(b[u].y,i)*b[b[u].x].w;
	else if (b[u].id==4)dm[u]=exp(b[b[u].x].w)*dfs1(b[u].x,i);
	else if (b[u].id==5)dm[u]=1.0/b[b[u].x].w*dfs1(b[u].x,i);
	else if (b[u].id==6)dm[u]=cos(b[b[u].x].w)*dfs1(b[u].x,i);
	return dm[u];
}

void mysolve()
{
	int n;
	cin>>n;
	set<int>s;
	int op;
	for (int i=0; i<n; ++i)
		{
			cin>>op;
			b[i].w=INF;
			if (op==0)cin>>b[i].w,s.insert(i);
			else if (op>=1&&op<=3)cin>>b[i].x>>b[i].y,in[b[i].x]++,in[b[i].y]++;
			else cin>>b[i].x,in[b[i].x]++;
			b[i].id=op;
		}
	int fa;
	for (int i=0; i<n; ++i)if (!in[i])
			{
				fa=i;
				printf("%.3lf\n",dfs(i));
				break;
			}
	bool flag=1;
	for (auto k:s)
		{
			for (int i=0; i<=n; ++i)dm[i]=INF;//每次求导记得初始化
			if (flag)flag=0,printf("%.3lf",dfs1(fa,k));
			else printf(" %.3lf",dfs1(fa,k));
		}
}

int32_t main()
{
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
