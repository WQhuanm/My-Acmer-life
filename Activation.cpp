#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e3 + 10;
double dp[N][N];
void mysolve()
{
	int n,m,k;
	double p1,p2,p3,p4;
	while(cin>>n>>m>>k>>p1>>p2>>p3>>p4)
	{
		if(1-fabs(p1+p2)<1e-6)//特判
		{
			cout<<"0.00000"<<endl;
			continue;
		}
		dp[1][1]=p4/(1-p1-p2);
		double p21=p2/(1-p1),p31=p3/(1-p1),p41=p4/(1-p1);//简化公式
		for(int i=2; i<=n; ++i)
		{
			double p=p21,tmp=p41;
			for(int j=2; j<=i; ++j)
			{
				p*=p21,tmp=tmp*p21+p31*dp[i-1][j-1];
				if(j<=k)tmp+=p41;//累加获得p'与tmp'
			}
			dp[i][i]=tmp/(1-p);//得到p[i][i]
			dp[i][1]=p21*dp[i][i]+p41;//获得p[i][1]
			for(int j=2; j<i; ++j)//可以正推了
			{
				dp[i][j]=p21*dp[i][j-1]+p31*dp[i-1][j-1];
				if(j<=k)dp[i][j]+=p41;
			}
		}
		printf("%.5lf\n",dp[n][m]);
	}
}

int32_t main()
{
	mysolve();
	return 0;
}
