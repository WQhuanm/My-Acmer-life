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

int a[4],b[N],dp[N][10];
void mysolve()
{
	int n;
	cin>>n>>a[1]>>a[2]>>a[3];
	for(int i=1; i<=n; ++i)cin>>b[i],memset(dp[i],0,sizeof(dp[i]));
	for(int i=1; i<=n; ++i)for(int x=0; x<8; ++x)
			{
				int cnt=0;
				if(i==1&&x!=0&&x!=4)continue;
				if(i==2&&(x&1))continue;
				for(int j=0; j<3; ++j)if(x&(1<<j))cnt++;
				if(cnt>b[i])continue;
				for(int y=0; y<8; ++y)
					{
						bool flag=1;
						for(int j=0; j<3; ++j)if(x&(1<<j)&&(y>>1)&(1<<j))flag=0;
						if(!dp[i-1][y]&&y)continue;
						if(flag)
							{
								int t=x|(y>>1);
								int tmp=x;
								x=t;
								if(tmp==0)dp[i][x]=max(dp[i][x],dp[i-1][y]);
								else if(tmp==4)dp[i][x]=max(dp[i][x],dp[i-1][y]+a[1]);
								else if(tmp==2)dp[i][x]=max(dp[i][x],dp[i-1][y]+a[2]);
								else if(tmp==1)dp[i][x]=max(dp[i][x],dp[i-1][y]+a[3]);
								else if(tmp==6)dp[i][x]=max(dp[i][x],dp[i-1][y]+a[1]+a[2]);
								else if(tmp==5)dp[i][x]=max(dp[i][x],dp[i-1][y]+a[1]+a[3]);
								else if(tmp==3)dp[i][x]=max(dp[i][x],dp[i-1][y]+a[2]+a[3]);
								else if(tmp==7)dp[i][x]=max(dp[i][x],dp[i-1][y]+a[1]+a[2]+a[3]);
								x=tmp;
							}
					}

			}
//	for(int i=1; i<=n; ++i)for(int x=0; x<8; ++x)cout<<i<<" : "<<x<<"    :"<<dp[i][x]<<endl;
	ll ans=0;
	for(int i=0; i<8; ++i)ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
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
