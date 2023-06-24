#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;
int a[N],l[N],r[N];
void mysolve()
{
	int n;
	cin>>n;
	map<int,vector<int>>mp;
	for(int i=1; i<=n; ++i)cin>>a[i],l[i]=l[i-1]+a[i];
//	if(n<3)
//		{
//			cout<<0<<endl;
//			return;
//		}
	for(int i=n; i; --i)r[i]=r[i+1]+a[i];
	for(int i=1; i<=n; ++i)mp[r[i]].push_back(i);
	int ans=0;
	for(int i=1; i<=n-2; ++i)
		{
			if(l[i]*2==l[n]-l[i])
				{
					if(!mp[l[i]].empty())
						{
							int tmp=(int)mp[l[i]].size()-(upper_bound(mp[l[i]].begin(),mp[l[i]].end(),i+1)-mp[l[i]].begin());
							ans+=tmp;
						}
				}
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
