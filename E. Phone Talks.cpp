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
const int N = 3e5 + 10;
const int mod = 998244353;

void mysolve()
{
	int n,k;
	cin>>n>>k;
	vector<pii>a(n+1);
	if(!n)
		{
			cout<<86400<<endl;
			return;
		}

	for(int i=1; i<=n; ++i)cin>>a[i].first>>a[i].second;
	int ans=0;
	vector dp(n+1,vector<int>(k+1));
	if(k+1<=n)ans=a[k+1].first-1;
	else
		{
			cout<<86400<<endl;
			return;
		}
	for(int i=1; i<=n; ++i)for(int j=0; j<=k; ++j)
			{
				if(dp[i-1][j]>=a[i].first)dp[i][j]=dp[i-1][j]+a[i].second;
				else
					{
						dp[i][j]=a[i].first+a[i].second-1;
						ans=max(ans,a[i].first-dp[i-1][j]-1);
					}

				if(j)
					{
						dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
					}
			}
	ans=max(ans,86400-dp[n][k]);
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
