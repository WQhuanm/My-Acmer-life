#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 2e5 + 10;

ll a[N];
int main()
{
	int t;
	cin>>t;
	while (t--)
		{
			int n,k,x;
			cin>>n>>k;
			fill(a,a+n+1,0);
			for (int i=0; i<n; ++i)
				{
					cin>>x;
					a[i%k]+=x;//把数分为k个集合，每次操作1就等效对每个集合操作
				}
			if (k==1)
				{
					cout<<0<<endl;
					continue;
				}
			sort(a,a+k);
			int len=0;
			int p=1;
			for (int i=1; i<k; ++i)
				{
					if (a[i]==a[i-1])p++;
					else
						{
							len=max(p,len),p=1;//最后一次操作1尽可能使多的集合变为0
						}
				}
			len=max(p,len);
			cout<<k-len<<endl;
		}
	return 0;
}
