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
const int N = 5e5 + 10;
const int mod = 998244353;

int b[N],a[N],cnt[N];
vector<int>pre[N];
void mysolve()
{
	int m,k,n,s,x,r=1;
	cin>>m>>k>>n>>s;
	for(int i=1; i<=m; ++i)cin>>a[i],pre[a[i]].push_back(i);
	for(int i=1; i<=s; ++i)
		{
			cin>>x,b[x]++;
			if((int)pre[x].size()<b[x])
				{
					cout<<-1<<endl;
					return;
				}
			else r=max(pre[x][b[x]-1],r);
		}

	for(int i=1; i<=r; ++i)cnt[a[i]]++;
	for(int i=1; i<=m+1-k; ++i)
		{
			int sum=(i-1)/k+(m-r)/k;
			if(sum>=n-1)
				{
					int ans=(i-1)%k;
					vector<int> res;
					for(int i=1; i<=ans; ++i)res.push_back(i);
					int len=r-i+1;
					for(int j=i; j<=r; ++j)if(len>k&&cnt[a[j]]>b[a[j]])res.push_back(j),cnt[a[j]]--,len--;
					cout<<res.size()<<endl;
					for(auto v:res)cout<<v<<" ";
					return;
				}

			cnt[a[i]]--;
			if(cnt[a[i]]<b[a[i]])
				{
					for(r=r+1; r<=m; ++r)
						{
							cnt[a[r]]++;
							if(a[r]==a[i])break;
						}
					if(cnt[a[i]]<b[a[i]])
						{
							cout<<-1<<endl;
							return;
						}
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
