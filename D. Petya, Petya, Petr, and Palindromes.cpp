#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 2e5 + 10;
vector<int>a[N][2];
int32_t main()
{
	int n,k,x,maxn=-1;
	cin>>n>>k;
	for (int i=1; i<=n; ++i)
		{
			cin>>x;
			maxn=max(maxn,x);
			a[x][i&1].push_back(i);//分奇偶性存入
		}
	if (k==1)//k=1不需处理
		{
			cout<<0<<endl;
			return 0;
		}
	ll ans=(n-k+1)*(k/2);//最多处理次数
	for (int i=1; i<=maxn; ++i)for (int j=0; j<2; ++j)
			{
				for (auto &x:a[i][j])
					{
						int l=max({1ll,x-k+1,2+k/2*2-x});//每次寻找出现在x之前的值为i的符合区间的数
						int r=min(x-2,2*n-x-k/2*2);
						if (l<=r)
							{
								ans-=upper_bound(a[i][j].begin(),a[i][j].end(),r)-lower_bound(a[i][j].begin(),a[i][j].end(),l);//合法区间里面存在的数个数
							}
					}
			}
	cout<<ans<<endl;
}
