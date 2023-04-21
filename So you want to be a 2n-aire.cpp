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
const int N = 35;
double dp[N];
int pre[N];
void mysolve()
{
	int n;
	double p;
	pre[0]=1;
	for(int i=1; i<=30; ++i)pre[i]=2*pre[i-1];
	while(cin>>n>>p&&(n||fabs(p)>1e-9))
	{
		dp[n]=pre[n];
		for(int i=n-1; i>=0; --i)
		{
			double tmp=pre[i]/dp[i+1];//答题与否的分界线
			if(p>=tmp)//大于就答题
			{
				dp[i]=(p+1)/2*dp[i+1];//因为是p~1的平均期望，取中间值
			}
			else
			{
				dp[i]=(tmp-p)/(1-p)*pre[i]+(1-tmp)/(1-p)*(tmp+1)/2*dp[i+1];//在p<tmp的情况下不答，发生概率是(tmp-p)/(1-p),剩下就是答题
			}
		}
		printf("%.3lf\n",dp[0]);
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
