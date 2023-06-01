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
const int N = 3e6 + 10;
const int mod = 998244353;

int a[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
		{
			cin>>a[i];
		}
	vector<int>v;
	for(int i=2; i<=n; ++i)v.push_back(a[i-1]-a[i]);
	sort(v.begin(),v.end());
	vector<int>sum(n+1);
	for(int i=0; i<(int)v.size(); ++i)sum[i+1]=sum[i]+v[i];
	int m;
	int op,k;
	cin>>m;
	while(m--)
		{
			cin>>op>>k;
			if(op==1)
				{
					cout<<sum[n-k]<<endl;
				}
		}
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

inline int read(int &x)
{
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9')ch = getchar();
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + ch - '0';
			ch = getchar();
		}
	return x;
}
