#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define endl             "\n"
#define int ll
int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t,q,op,a,b,n,x,y;
	cin>>t;
	while (t--)
		{
			cin>>q;
			int l=1,r=1e18;
			while (q--)
				{
					cin>>op>>a>>b;
					if (op==1)
						{
							cin>>n;
							if (n==1)
								{
									x=1,y=a;
								}
							else
								{
									x=1+a*(n-1)-b*(n-2);
									y=(a-b)*(n-1)+a;
								}
							if (y>=l&&x<=r)//判断是否采用，是则更新区间，尽量缩小它
								{
									cout<<1<<" ";
									l=max(l,x),r=min(r,y);
								}
							else cout<<0<<" ";
						}
					else
						{
							x=a>=l?1LL:(l-b+a-b-1)/(a-b);
							y=a>=r?1LL:(r-b+a-b-1)/(a-b);
							if (x==y)cout<<x<<" ";
							else cout<<-1<<" ";
						}
				}
			cout<<endl;
		}
	system("pause");
	return 0;
}
