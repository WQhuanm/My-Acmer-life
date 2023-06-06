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

void mysolve()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	set<int>st;
	for(int i=0; i<n; ++i)
		{
			if(s[i]=='('&&i&1)st.insert(i);
			else if(s[i]==')'&&i%2==0)st.insert(i);
		}
	while(q--)
		{
			int x;
			cin>>x;
			x--;
			if(n&1)cout<<"NO"<<endl;
			else
				{
					if(st.count(x))st.erase(x);
					else st.insert(x);
					if(!st.empty()&&((*st.begin())%2==0||(*prev(st.end())&1)))cout<<"NO"<<endl;
					else cout<<"YES"<<endl;
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
