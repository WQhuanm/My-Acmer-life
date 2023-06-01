#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
inline int read(int &x);
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 1e6 + 10;
int mod = 998244353;
int sum[N],a[N];
void mysolve()
{
	int k,n,x;
	cin>>k;
	for(int i=1; i<=k; ++i)cin>>a[i];
	cin>>n>>mod>>x;
	for(int i=1; i<=k; ++i)sum[i]=(sum[i-1]+a[i]%mod);
	int end=(x%mod+n/k*sum[k]+sum[n%k])/mod;
	cout<<n-end<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

