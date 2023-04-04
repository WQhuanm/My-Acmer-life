#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define endl             "\n"
#define int ll
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF

int32_t main()
{
	int n,m;
	cin>>n>>m;
	if (n>1e6||n*n>=m)//或者防止除法溢出
		{
			int ans=llINF;
			for (int i=1; i<=n; ++i)
				{
					int x=(m+i-1)/i;//向上取整
					if (x<=n)ans=min(ans,x*i);
					if (i>x)break;
				}
			cout<<ans<<endl;
		}
	else cout<<-1<<endl;
	return 0;
}
