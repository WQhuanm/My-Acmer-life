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

ll a[N],t[N];
int n;

inline void add(int x,ll w)
{
	for(int i=x; i<=n; i+=i&-i)t[i]=(t[i]+w);
}

inline ll ask(int x)//区间[1,x]的和
{
	ll ans=0;
	for (int i=x; i; i-=i&-i)ans=(ans+t[i]);
	return ans;
}

void mysolve()
{
	string s[3];
	cin>>s[1]>>s[2];
	s[1]="$"+s[1];
	s[2]="$"+s[2];
	int t,q;
	cin>>t>>q;
	int cnt=0;
	for(int i=0; i<(int)s[1].size(); ++i)if(s[1][i]!=s[2][i])++cnt;
	int op,p1,p2,ps1,ps2;
	deque<int>p;
	for(int i=1; i<=q; ++i)
		{
			cin>>op;
			while(!p.empty()&&p.front()<=i)cnt++,p.pop_front();
			if(op==1)
				{
					cin>>ps1;
				//	ps1--;
					if(s[1][ps1]!=s[2][ps1])p.push_back(i+t),cnt--;
				}
			else if(op==2)
				{
					cin>>p1>>ps1>>p2>>ps2;
					if(ps1==ps2)swap(s[p1][ps1],s[p2][ps2]);
					else
						{
							if(s[p1][ps1]!=s[(p1==1?2:1)][ps1])cnt--;
							if(s[p2][ps2]!=s[(p2==1?2:1)][ps2])cnt--;
							swap(s[p1][ps1],s[p2][ps2]);
							if(s[p1][ps1]!=s[(p1==1?2:1)][ps1])cnt++;
							if(s[p2][ps2]!=s[(p2==1?2:1)][ps2])cnt++;
						}
				}
			else
				{
					if(cnt)cout<<"NO"<<endl;
					else cout<<"YES"<<endl;
				}
		}

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
