#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
typedef pair<int, int> pii;
inline int read(int &x);
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;
int n,k,a[N];

bool check(ll mid)
{
	priority_queue<int>q;
	ll sum=0;
	vector<int>cnt(n+1);
	for(int i=1; i<=n; ++i)
		{
			sum+=a[i],q.push(a[i]);
			while(sum>mid)
				{
					sum-=q.top();
					q.pop();
				}
			cnt[i]=q.size();//堆维护前i个数最多可以选几个
		}
	q=priority_queue<int>();
	sum=0;
	for(int i=n; i; --i)
		{
			sum+=a[i],q.push(a[i]);
			while(sum>mid)
				{
					sum-=q.top(),q.pop();
				}//维护后n-i+1个数最多可以选几个
			if((int)q.size()+cnt[i-1]>=k)return 1;
		}
	return 0;
}
void mysolve()
{
	cin>>n>>k;
	ll sum=0;
	for(int i=1; i<=n; ++i)cin>>a[i],sum+=a[i];
	ll l=1,r=sum;
	ll ans=sum;
	while(l<=r)//二分答案
		{
			ll mid=l+((r-l)>>1);
			if(check(mid))ans=mid,r=mid-1;
			else l=mid+1;
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
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
