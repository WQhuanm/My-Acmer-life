#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;
int a[N];
int n;
int MEX()
{
	map<int,int>mp;
	for(int i=1; i<=n; ++i)mp[a[i]]++;
	for(int i=0; i<=n; ++i)if(!mp[i])return i;
}
void mysolve()
{
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i];
	int mex=MEX();
	int l=n+1,r=0;
	for(int i=1; i<=n; ++i)if(a[i]==mex+1)l=min(l,i),r=max(r,i);
	if(r)//如果有mex+1，修改区间
		{
			for(int i=l; i<=r; ++i)a[i]=mex;
			int tmp=MEX();
			if(tmp==mex+1)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	else//没有，看看是不是能修改
		{
			if(mex==n)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}

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
