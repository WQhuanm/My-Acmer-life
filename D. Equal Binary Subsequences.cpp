#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;

void mysolve()
{
	int n;
	string s;
	cin>>n>>s;
	s="$"+s;
	if(count(s.begin(),s.end(),'1')&1)
		{
			cout<<-1<<endl;
			return;
		}
	vector<int>m;
	int p=1;
	for(int i=1; i<(int)s.size(); i+=2)
		{
			if(s[i]!=s[i+1])
				{
					m.push_back(i);
					if(s[i]-'0'!=p)m.back()++;
					p^=1;
				}
		}
	cout<<(int)m.size();
	for(auto v:m)cout<<" "<<v;
	cout<<endl;
	for(int i=1; i<=n; ++i)cout<<2*i-1<<" \n"[i==n];
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
