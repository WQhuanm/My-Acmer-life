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
string s;
ll ans;
#define mid l+((r-l)>>1)

int cnt[N];

void dfs(int l,int r)
{
	if(l==r)
		{
			ans+=s[l]=='1';
//			if(s[l]=='1')cout<<l<<" "<<l<<endl;
			return ;
		}
	dfs(l,mid),dfs(mid+1,r);
	int j=mid+1,i=j;
	int res=(s[j]=='1'?1:0);
	while(i>l&&res<=2e6+10)
		{
			if(s[i-1]=='1')
				{
					int tmp=1<<(min(25ll,j-i+1));
					if(res+tmp<=2e6)res+=tmp;
					else break;
				}
			i--;
		}
	for(; i<=mid; ++i)
		{
			if(s[i]=='0')continue;
			int tmp=res;
			for(int p=mid+1; p<=r&&p<=mid+26; ++p)
				{

					if(p-i+1==tmp)
						{
							ans++;
//							cout<<i<<" "<<p<<endl;
						}
					else if(cnt[i]+p-i+1>=tmp)ans++;
					tmp<<=1;
					if(s[p+1]=='1')tmp++;
				}
			if(s[i]=='1')res-=1<<(j-i);

		}

}

void mysolve()
{
	ans=0;
	cin>>s;
	s.push_back('$');
	int	p=0;
	for(int i=0; i<(int)s.size(); ++i)
		{
			cnt[i]=p;
			if(s[i]=='0')p++;
			else p=0;
		}
	dfs(0,(int)s.size()-2);
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
