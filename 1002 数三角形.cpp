#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define int              long long
typedef pair<int, int> pii;
const int N = 3e5 + 10,G = 3, Gi = 332748118;
const int mod=998244353;

vector<pii>pre[15];
int limit,L;
int r[N];
void init()
{
	pre[3].push_back({4,5+4});
	pre[4].push_back({3,5+3});
	pre[5].push_back({12,13+12});
	pre[6].push_back({8,10+8});
	pre[7].push_back({24,25+24});
	pre[8].push_back({6,10+6});
	pre[8].push_back({15,17+15});
	pre[9].push_back({12,15+12});
	pre[9].push_back({40,41+40});
	pre[10].push_back({24,26+24});
}

ll fastmi(ll base, ll power)
{
	ll ans = 1;
	while (power)
		{
			if (power & 1)ans=ans*base%mod;
			base=base*base%mod;
			power >>=1;
		}
	return ans;
}

inline void NTT(ll *A, int type)
{
	for(int i = 0; i < limit; i++)
		if(i < r[i]) swap(A[i], A[r[i]]);
	for(int mid = 1; mid < limit; mid <<= 1)
		{
			ll Wn = fastmi( type == 1 ? G : Gi, (mod - 1) / (mid << 1));
			for(int j = 0; j < limit; j += (mid << 1))
				{
					ll w = 1;
					for(int k = 0; k < mid; k++, w = (w * Wn) % mod)
						{
							int x = A[j + k], y = w * A[j + k + mid] % mod;
							A[j + k] = (x + y) % mod,
							           A[j + k + mid] = (x - y + mod) % mod;
						}
				}
		}
}

ll aa[N],bb[N];
void mysolve()
{
	vector<int>a1,b1;
	unordered_map<int,int>a,b;
	int n,A,B;
	cin>>n>>A>>B;
	int x1,y1;
	for(int i=1; i<=n; ++i)
		{
			cin>>x1>>y1;
			if(y1==A)a[x1]=1,a1.push_back(x1);
			else b[x1]=1,b1.push_back(x1);
		}
	int ans=0;
	int d=abs(A-B);
	sort(a1.begin(),a1.end()),sort(b1.begin(),b1.end());

	for(auto v:a1)//暴力枚举第一种
		{
			for(pii u:pre[d])
				{
					if(b.count(v+u.first)&&b.count(v+u.second))ans++;
					if(b.count(v-u.first)&&b.count(v-u.second))ans++;
					if(b.count(v+u.first)&&b.count(v-(u.second-2*u.first)))ans++;
					if(b.count(v-u.first)&&b.count(v+(u.second-2*u.first)))ans++;
				}
			if(b.count(v+d)&&b.count(v))ans++;
			if(b.count(v-d)&&b.count(v))ans++;
			ans%=mod;
		}
	for(auto v:b1)
		{
			for(pii u:pre[d])
				{
					if(a.count(v+u.first)&&a.count(v+u.second))ans++;
					if(a.count(v-u.first)&&a.count(v-u.second))ans++;
					if(a.count(v+u.first)&&a.count(v-(u.second-2*u.first)))ans++;
					if(a.count(v-u.first)&&a.count(v+(u.second-2*u.first)))ans++;
				}
			if(a.count(v+d)&&a.count(v))ans++;
			if(a.count(v-d)&&a.count(v))ans++;
			ans%=mod;
		}

	limit=1,L=0;//NNT计算i+j枚举后各个数的出现次数
	while(limit<=2e5)limit<<=1,L++;
	for(int i = 0; i < limit; i++)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
	for(int i=0; i<=1e5; ++i)
		{
			if(a[i])aa[i]=1;
			if(b[i])bb[i]=1;
		}
	NTT(aa,1),NTT(bb,1);
	for(int i=0; i<limit; ++i)aa[i]=aa[i]*aa[i]%mod,bb[i]=bb[i]*bb[i]%mod;//多项式a*a
	NTT(aa,-1),NTT(bb,-1);
	ll inv=fastmi(limit,mod-2);
	for(int i=0; i<=2e5; ++i)aa[i]=aa[i]*inv%mod,bb[i]=bb[i]*inv%mod;

	int res=0;
	for(int i=0; i<=1e5; ++i)
		{
			if(a[i])res+=bb[i<<1]-b[i];//减去i+i的情况
			if(b[i])res+=aa[i<<1]-a[i];
		}
	ans=(ans+res/2)%mod;//因为i+j与j+i各自算了一次，要除2
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			init();
			mysolve();
		}
	system("pause");
	return 0;
}
