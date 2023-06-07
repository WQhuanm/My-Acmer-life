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
const int N = 3e5 + 10;
const int mod = 998244353;

pii a[N];
int l[N],r[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)
		{
			cin>>a[i].first;
			a[i].second=i;
			l[i]=i,r[i]=n;
		}
	stack<pii>s;
	s.push(a[1]);
	for(int i=2; i<=n; ++i)
		{
			while(!s.empty()&&a[i].first<s.top().first)r[s.top().second]=i-1,s.pop();
			if(!s.empty()&&s.top().first==a[i].first)l[i]=l[s.top().second];
			else if(!s.empty())l[i]=s.top().second+1;
			else l[i]=1;
			s.push(a[i]);
		}
	sort(a+1,a+1+n);
	unordered_map<int,pii>mp;
	int x1=0,y1=0;
	for(int i=n; i ; --i)
		{
			int x=l[a[i].second],y=r[a[i].second];
			if(y-x>y1-x1)y1=y,x1=x;
			else x=x1,y=y1;
			if(!mp[a[i].first].first)mp[a[i].first]= {x,y};
			else
				{
					int len=mp[a[i].first].second-mp[a[i].first].first;
					if(y-x>len)mp[a[i].first]= {x,y};
				}
		}
	for(int i=1; i<=n; ++i)
		{
			int L=1,R=n;
			int ans=a[1].first;
			while(L<=R)
				{
					int mid=L+((R-L)>>1);
					int len=mp[a[mid].first].second-mp[a[mid].first].first+1;
					if(len>=i)ans=a[mid].first,L=mid+1;
					else R=mid-1;
				}
			cout<<ans<<" ";
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
