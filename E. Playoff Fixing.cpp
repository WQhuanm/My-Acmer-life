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
const int N = 1e6 + 10;
const int mod=998244353;

int dp[N];
int a[N],b[N],pre[N];

void mysolve()
{
	int K,n;
	pre[0]=1;
	cin>>K;
	n=1<<K;
	int x;
	for(int i=1; i<=n; ++i)pre[i]=pre[i-1]*i%mod,a[i]=-1;//预处理排列
	for(int i=1; i<=n; ++i)
		{
			cin>>x;
			if(~x)a[x]=i;
		}

	int ans=1,p=(1<<K)-1;
	for(int k=K-1; ~k; --k)
		{
			for(int i=(1<<k)+1; i<=1<<(k+1); ++i)if(~a[i])dp[(p+a[i])>>(K-k)]++;//处理这一层要输的人在哪个指定的位置输
			for(int i=1; i<=(1<<k); ++i)if(~a[i])b[(p+a[i])>>(K-k)]++;//处理这一层前面的人有没有在哪个指定的位置赢
			int cnt=0,tmp=1;
			for(int i=1<<k; i<(1<<(k+1)); ++i)//枚举这一层每一个位置
				{

					if(dp[i]>=2||b[i]>=2)//如果这个位置指定赢的人/输的人>=2，无解
						{
							cout<<0<<endl;
							return;
						}
					else if(!dp[i])cnt++,tmp=tmp*(b[i]?1:2)%mod;//这个位置没有被输的人指定，那么cnt+1，如果这个位置的两个空位都没有被指定哪个位置是赢的人要的，tmp*2
				}
			ans=ans*pre[cnt]%mod*tmp%mod;
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
