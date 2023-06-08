#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f

typedef pair<int,int> pii;
const int N = 3e5 + 10;
int a[N];
pii b[N];
void mysolve()
{
	int m,k,x,y;
	cin>>m>>k;
	for(int i=1; i<=k; ++i)cin>>a[i];
	int cnt=0;
	bool flag=1;
	m--;
	multiset<int>s;
	for(int i=1; i<=m; ++i)cin>>b[i].first>>b[i].second,s.insert(b[i].first);
	for(int i=1; i<=m; ++i)
		{
			x=b[i].first,y=b[i].second;
			if(flag&&y)
				{
					int mn=cnt;
					for(int i=1; i<=k; ++i)
						{
							if(a[i]<=cnt&&!s.count(i))
								{
									mn=min(mn,a[i]);
								}
						}
					for(int i=1; i<=k; ++i)
						{
							if(a[i]<=cnt&&!s.count(i))
								{
									//	mn=min(mn,a[i]);
									a[i]-=cnt;
								}
							else a[i]-=cnt-mn;
						}
					cnt=0;
					flag=0;
				}
			if(x)
				{
					a[x]--;
					if(a[x]<=0)flag=0;
				}
			else cnt++;
			s.erase(s.find(x));
		}

	for(int i=1; i<=k; ++i)
		{
			if(a[i]-cnt<=0)cout<<"Y";
			else cout<<"N";
		}
	cout<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

