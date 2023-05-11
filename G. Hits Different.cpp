#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e6+ 10;

int dp[N];
void mysolve()
{
	int n;
	cin>>n;
	cout<<dp[n]<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	dp[1]=1;
	int len=2,p=1;
	for(int i=2; i<=1e6; ++i)//预处理
		{
			if(p==1)dp[i]=i*i+dp[i-len+1];
			else if(p==len)dp[i]=i*i+dp[i-len];
			else
				{
					dp[i]=i*i+dp[i-len+1]+dp[i-len]-dp[i-len-(len-1)+1];//要减去上方重复的
				}
			p++;
			if(p>len)len++,p=1;
		}
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
