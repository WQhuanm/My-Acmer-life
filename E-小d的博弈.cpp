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
const int N = 510;
int dp[N];

int sg(int x)
{
	if(x<=0)return 0;
	if(~dp[x])return dp[x];
	set<int>s;
	for(int i=x/2+1; i<x; ++i)s.insert(sg(x-i));
	int ans=0;
	while(s.count(ans))ans++;
	return dp[x]=ans;
}
void mysolve()
{
	//sg打表
//	memset(dp,-1,sizeof(dp));
//	for(int i=1; i<=30; ++i)for(int j=1; j<=30; ++j)
//			{
//				cout<<(sg(i)^sg(j))<<" ";
//				if(j==30)cout<<endl;
//			}
	int x,y;
	cin>>x>>y;
	int l=1;
	while(1)
		{
			x-=(1ll<<l);
			y-=(1ll<<l);
			if(x<=0&&y<=0)
				{
					cout<<"Bob"<<endl;
					return;
				}
			else if((x>0&&y<=0)||(y>0&&x<=0))
				{
					cout<<"Alice"<<endl;
					return;
				}
			l++;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

