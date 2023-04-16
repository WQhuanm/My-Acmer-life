#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1010;
double dp[N][N];
struct node
{
	double a,b,c;
};
node a[N][N];
void mysolve()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
		{
			memset(dp,0,sizeof(dp));
			for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j)scanf("%lf%lf%lf",&a[i][j].a,&a[i][j].b,&a[i][j].c);
			dp[n][m]=0;
			for(int i=n; i>=1; --i)for(int j=m; j>=1; --j)if(i!=n||j!=m)
						{
							if(fabs(1.0-a[i][j].a)<1e-6)continue;//有可能原地为1，这样除0必定WA
							dp[i][j]=(dp[i][j+1]*a[i][j].b+dp[i+1][j]*a[i][j].c+2)/(1-a[i][j].a);
						}
			printf("%.3lf\n",dp[1][1]);
		}

}

int32_t main()
{
	//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
