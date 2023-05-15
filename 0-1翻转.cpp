#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
typedef pair<int, int> pii;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 3e5 + 10;

void mysolve()
{
	vector<int>a,b;
	int n;
	string s;
	cin>>n>>s;
	for(int i=0; i<n; ++i)if(s[i]=='1')
			{
				if(i&1)a.push_back(i);
				else b.push_back(i);
			}
	if(a.size()!=b.size())cout<<-1<<endl;
	else
		{
			int ans=0;
			for(int i=0; i<(int)a.size(); ++i)ans+=abs(a[i]-b[i]);
			cout<<ans<<endl;
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
