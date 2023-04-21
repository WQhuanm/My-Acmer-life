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
const int N = 4e3 + 10;
double dp[N][4];
double p[N][4];
void mysolve()
{
	int t,n,a,b;
	cin>>t;
	while(t--)
		{
			cin>>n>>a>>b;
			memset(p, 0, sizeof(p));
			memset(dp,0,sizeof(dp));
			for(int i=1; i<=n; ++i)
				{
					scanf("%lf %lf %lf %lf",&p[i][0],&p[i][1],&p[i][2],&p[i][3]);
				}
			dp[n][1]=dp[n][2]=dp[n][3]=1;
			for(int i = n + 1; i <= n + b; i++) p[i][3] = 1;
			for(int i=n-1; i>=0; --i)
				{
					double t1=1.0,t2=1.0,t3=1.0;
					for(int j=a; j<=b; ++j)
						{
							int k=i+j;
							dp[i][1]+=t1*(p[k][1]*(dp[k][2]+1)+p[k][3]*(dp[k][3]+1)),t1*=(p[k][0]+p[k][2]);
							dp[i][2]+=t2*(p[k][2]*(dp[k][1]+1)+p[k][3]*(dp[k][3]+1)),t2*=(p[k][0]+p[k][1]);
							dp[i][3]+=t3*(p[k][1]*(dp[k][2]+1)+p[k][2]*(dp[k][1]+1)+p[k][3]*(dp[k][3]+1)),t3*=p[k][0];
						}
				}
			printf("%.8lf\n",dp[0][3]);
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
