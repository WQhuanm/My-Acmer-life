#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef unsigned long long ull;
typedef pair<int, int> pii;
inline int read(int &x);
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

ll f[N];

ll fastmi(ll base,ll power)
{
	ll ans=1;
	while(power)
		{
			if(power&1)ans=ans*base%mod;
			power>>=1,base=base*base%mod;
		}
	return ans;
}
void mysolve()
{
	mt19937_64 rnd(random_device{}());
	uniform_int_distribution<ull> dist(0, ULLONG_MAX);
	int n,k;
	cin>>n>>k;
	vector<int>b(n+5);
	int l,r;
	for(int i=1; i<=k; ++i)
		{
			cin>>l>>r;
			ull h=dist(rnd);
			b[l]^=h,b[r+1]^=h;
		}
	if(n&1)
		{
			cout<<0<<endl;
			return;
		}
	map<ull,int>mp;
	for(int i=1; i<=n; ++i)
		{
			b[i]^=b[i-1];
			mp[b[i]]++;
		}
	int ans=1;
	for(auto [k,v]:mp)
		{
			if(v&1)//要求被割裂的每个段都是偶数长度
				{
					cout<<0<<endl;
					return;
				}
			ans=ans*f[v/2]%mod;
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	//read(t);
	f[0]=1;
	for(int i=1; i<=3e5; ++i)
		f[i]=f[i-1]*(4*i-2)%mod*fastmi(i+1,mod-2)%mod;//预处理卡特兰数
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
