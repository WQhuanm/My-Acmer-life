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
double dp[N];
void mysolve()
{
	int n,m;
	while(cin>>n>>m&&(n||m))
		{
			dp[n]=0.0;
			vector<int>a(n+1);
			int x,y;
			while(m--)cin>>x>>y,a[x]=y;
			double p=1.0/6;
			for(int i=n-1; i>=0; --i)
				{
					if(a[i])dp[i]=dp[a[i]];
					else
						{
							dp[i]=1+p*(dp[min(n,i+1)]+dp[min(n,i+2)]+dp[min(n,i+3)]+dp[min(n,i+4)]+dp[min(n,i+5)]+dp[min(n,i+6)]);
						}
				}
			printf("%.4lf\n",dp[0]);
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
