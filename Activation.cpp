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
const int N = 2e3 + 10;
double dp[2][N];
void mysolve()
{
	int n,m,k;
	double p1,p2,p3,p4;
	while(cin>>n>>m>>k>>p1>>p2>>p3>>p4)
		{
			if(fabs(1-p1-p2)<1e-6)
			//if(p4<1e-6)
				{
					cout<<"0.00000"<<endl;
					continue;
				}
			int t=0;
			dp[t][1]=p4/(1-p1-p2);
			double p21=p2/(1-p1),p31=p3/(1-p1),p41=p4/(1-p1);
			for(int i=2; i<=n; ++i)
				{
					t^=1;
					double tmp=p41,p=p21;
					for(int j=2; j<=i; ++j)
						{
							p*=p21,tmp=tmp*p21+dp[t^1][j-1]*p31;
							if(j<=k)tmp+=p41;
						}
					dp[t][i]=tmp/(1-p);
					dp[t][1]=dp[t][i]*p21+p41;
					for(int j=2; j<i; ++j)
						{
							dp[t][j]=dp[t][j-1]*p21+dp[t^1][j-1]*p31;
							if(j<=k)dp[t][j]+=p41;
						}
				}
			printf("%.5lf\n",dp[t][m]);
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
