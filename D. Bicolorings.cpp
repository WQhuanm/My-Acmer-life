#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
inline int read(int &x);
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 2e3 + 10;
const int mod = 998244353;

int dp[N][N][5];
void mysolve()
{
	int n,k;
	cin>>n>>k;
	dp[1][1][0]=dp[1][1][3]=1;
	dp[1][2][1]=dp[1][2][2]=1;
	for(int i=2; i<=n; ++i)for(int j=1; j<=k; ++j)
			{
				for(int x=0; x<4; ++x)for(int y=0; y<4; ++y)
						{
							if((x^y)==3&&(y==1||y==2)&&j>3)dp[i][j][x]=(dp[i][j][x]+dp[i-1][j-2][y])%mod;
							else if(!(x^y))dp[i][j][x]=(dp[i][j][x]+dp[i-1][j][y])%mod;
							else if(y==1||y==2)
								{
									if(x==0||x==3)dp[i][j][x]=(dp[i][j][x]+dp[i-1][j][y])%mod;
								}
							else if(y==0||y==3)
								{
									if(j>1)dp[i][j][x]=(dp[i][j][x]+dp[i-1][j-1][y])%mod;
								}

						}
			}
	int ans=0;
	for(int i=0; i<4; ++i)ans=(ans+dp[n][k][i])%mod;
	cout<<ans<<endl;

}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

inline int read(int &x)
{
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9')ch = getchar();
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + ch - '0';
			ch = getchar();
		}
	return x;
}
