#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define endl             "\n"
const int N = 5e3 + 10;
const int mod=1e9+7;

ll c[N][N];
void init()
{
	c[0][0]=1;
	for (int i=1; i<=5e3; ++i)
		{
			c[i][0]=1;
			for (int j=1; j<=i; ++j)c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,n,x;
	cin>>t;
	init();
	while (t--)
		{
			cin>>n>>x;
			if (n+1>x)
				{
					cout<<-1<<endl;
					continue;
				}
			else
				{
					cout<<c[x][n+1]<<endl;
				}
		}
	return 0;
}

