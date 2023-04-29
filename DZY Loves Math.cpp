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
const int N = 2e4 + 10;
vector<int>at[N];
int n,m,len,ans;

int getcnt(int x,int val)
{
	int cnt=-1,l=0,r=(int)at[x].size()-1;
	while(l<=r)
		{
			int mid=l+((r-l)>>1);
			if(at[x][mid]<=val)cnt=mid,l=mid+1;
			else r=mid-1;
		}
	return cnt+1;
}

void dfs(int pos,int a,int b)
{
	if(pos==len)
		{
			int sum=b-a,L=b-n,R=m-a;
			if(!a)R=min(R,b-1),L=max(1ll,L);
			if(L>R)return;
			ans+=__gcd(a,b)*(getcnt(sum,R)-getcnt(sum,L-1));
			//	cout<<a<<" "<<b<<" "<<ans<<endl;
			return;
		}
	dfs(pos+1,a,b);
	dfs(pos+1,a,b|(1<<pos));
	if((a|(1<<pos))<=m)dfs(pos+1,a|(1<<pos),b|(1<<pos));
}

void mysolve()
{
	cin>>n>>m;
	if(n<m)swap(n,m);
	ans=0,len=0;
	while((1<<len)<=n)len++;
	for(int i=0; i<(1<<len); ++i)
		{
			at[i].clear();
			for(int j=i; ; j=(j-1)&i)
				{
					at[i].push_back(j);
					if(!j)break;
				}
			sort(at[i].begin(),at[i].end());
		}
	dfs(0,0,0);
	cout<<ans<<endl;
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
