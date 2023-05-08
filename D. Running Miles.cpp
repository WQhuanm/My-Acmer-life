#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int INF = 0x3f3f3f3f;         //int型的INF
const int N = 2e5 + 10;
int a[N],l[N],r[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i],l[i]=max(l[i-1],a[i]+i);
	r[n+1]=-INF;
	for(int i=n; i>=1; --i)r[i]=max(r[i+1],a[i]-i);//预处理前后缀最大值
	int ans=-INF;
	for(int i=2; i<n; ++i)ans=max(ans,a[i]+l[i-1]+r[i+1]);
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
