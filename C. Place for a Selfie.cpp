#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define endl             "\n"
#define int ll
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 10;

int d[N];
int n,m;

int toit(int x)
{
	int l=1,r=n,ans=INF,book=0;
	while (l<=r)
		{
			int mid=l+((r-l)>>1);
			if (abs(d[mid]-x)<ans)ans=abs(d[mid]-x),book=mid;
			if (d[mid]>=x)	r=mid-1;
			else l=mid+1;
		}
	return d[book];
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin>>t;
	while (t--)
		{

			cin>>n>>m;
			for (int i=1; i<=n; ++i)cin>>d[i];
			sort(d+1,d+1+n);
			d[0]=INF;
			int a,b,c;
			while (m--)
				{
					cin>>a>>b>>c;
					int k=toit(b);
					int tmp=(k-b)*(k-b)-4*a*c;
					if (tmp<0)
						{
							cout<<"YES"<<endl;
							cout<<k<<endl;
						}
					else cout<<"NO"<<endl;
				}
		}
	system("pause");
	return 0;
}
