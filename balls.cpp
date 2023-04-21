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
const int N = 1e3 + 10;
double a[N][N],p[N][N];

void mysolve()
{
	int n,m;
	while(cin>>n>>m)
		{
			vector<double>sum(m+1,0.0);
			double ans=0;
			for(int i=1; i<=n; ++i)
				{
					double tmp=0.0;
					for(int j=1; j<=m; ++j)scanf("%lf",&a[i][j]),tmp+=a[i][j];
					for(int j=1; j<=m; ++j)p[i][j]=a[i][j]*1.0/tmp,sum[j]+=p[i][j],ans+=p[i][j];
				}
			for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j)ans+=(sum[j]-p[i][j])*p[i][j];
			printf("%.2lf\n",ans);
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
