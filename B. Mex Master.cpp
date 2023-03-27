#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 2e5 + 10;

int a[N];

int main()
{std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,n;
	cin>>t;
	while (t--)
		{
			cin>>n;
			for (int i=1; i<=n; ++i)cin>>a[i];
			int zero=count(a+1,a+1+n,0),one=count(a+1,a+1+n,1);
			if (zero<=n-zero+1)
				{
					cout<<0<<endl;
				}
			else if (one+zero==n&&zero<n)cout<<2<<endl;
			else cout<<1<<endl;
		}
	return 0;
}
