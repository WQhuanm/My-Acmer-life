#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 4e5 + 10;
int a[N];
int main()
{
	int t,n;
	cin>>t;
	while (t--)
		{
			cin>>n;
			int ans=0;
			for (int i=1; i<=2*n; ++i)cin>>a[i],ans+=abs(a[i]);
			if (n==1)
				{
					ans=abs(a[1]-a[2]);
				}
			else if (n==2)
				{
					int tmp=0;
					for (int i=1; i<=2*n; ++i)tmp+=abs(a[i]-2);
					ans=min(ans,tmp);
				}
			else if (n%2==0)
				{
					int tmp=0;
					for (int i=1; i<=2*n; ++i)tmp+=abs(a[i]+1);
					for (int i=1; i<=2*n; ++i)
						{
							ans=min(ans,tmp-abs(a[i]+1)+abs(a[i]-n));
						}
				}
			cout<<ans<<endl;
		}
	return 0;
}
