#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const double eps=1e-9;
const int N = 110;
int n,m;
double a[N][N];

void print()//打印看目前情况
{
	cout<<endl;
	for(int i=1; i<=n; ++i)for(int j=1; j<=m+1; ++j)cout<<a[i][j]<<" \n"[j==n+1];
	cout<<endl;
}

void gauss()
{
	int r=1;//r表示目前处理到第r行
	
	for(int i=1; i<=m&&r<=n; ++i)//处理列数不超过m列，成功处理的列数也要小于行数（最多n行可处理，你列数再多也没用）
		{
			int mx=r;
			for(int j=r+1; j<=n; ++j)if(fabs(a[j][i]>fabs(a[mx][i])))mx=j;//第r次处理，但是比较的还是目前第i列元素（前面有可能有的列不用处理）
			if(fabs(a[mx][i])<eps)continue;//最大主元为0，当前列都为0，不用处理
			if(mx!=r)for(int j=1; j<=n+1; ++j)swap(a[r][j],a[mx][j]);//把主元最大的行提到第r行来处理
			for(int j=1; j<=n; ++j)if(j!=r)//处理不是第r行的其他行
					{
						double tmp=a[j][i]/a[r][i];
						for(int k=r; k<=n+1; ++k)a[j][k]-=a[r][k]*tmp;
					}
			r++;//最后这里r是多加了一次
			//	print();
		}

	for(int i=r; i<=n; ++i)if(fabs(a[i][n+1])>eps)//存在零行,这里r是未处理的，多加了一次
			{
				cout<<-1<<endl;//0行但是b！=0
				return;
			}
	if(r<=m)//存在自由元，有无穷解
		{
			cout<<0<<endl;
			return;
		}
	else for(int i=1; i<=n; ++i)printf("x%d=%.2lf\n",i,fabs(a[i][n+1]/a[i][i])<eps?0.00:a[i][n+1]/a[i][i]);//防止-0,00出现

}
void mysolve()
{
	cin>>n;
	m=n;
	for(int i=1; i<=n; ++i)for(int j=1; j<=n+1; ++j)cin>>a[i][j];
	gauss();
}

int32_t main()
{
	mysolve();
	system("pause");
	return 0;
}
