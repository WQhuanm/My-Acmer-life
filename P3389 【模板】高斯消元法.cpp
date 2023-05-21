#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const double eps=1e-9;
const int N =110;

double a[N][N];
int n;

void print()
{
	cout<<endl;
	for(int i=1; i<=n; ++i)for(int j=1; j<=n+1; ++j)cout<<a[i][j]<<" \n"[j==n+1];
	cout<<endl;
}

void gauss()
{
	for(int i=1; i<=n; ++i) //枚举第i列
		{
				print();
			int mx=i;
			for(int j=i+1; j<=n; ++j)if(fabs(a[j][i])>fabs(a[mx][i]))mx=j;
			if(fabs(a[mx][i])<eps)
				{
					cout<<"No Solution"<<endl;
					return;
				}
			if(mx!=i)for(int j=1; j<=n+1; ++j)swap(a[i][j],a[mx][j]);
			for(int j=1; j<=n; ++j)if(j!=i)//更新第j行
					{
						double tmp=a[j][i]/a[i][i];
						for(int k=i; k<=n+1; ++k)a[j][k]-=tmp*a[i][k];
					}
		}print();
	for(int i=1; i<=n; ++i)printf("%.2lf\n",a[i][n+1]/a[i][i]);
}

void mysolve()
{
	cin>>n;
	for(int i=1; i<=n; ++i)for(int j=1; j<=n+1; ++j)cin>>a[i][j];
	gauss();
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
