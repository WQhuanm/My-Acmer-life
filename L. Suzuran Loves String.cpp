#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

void mysolve()
{
	string s;
	cin>>s;
	int p=0;
	for(int i=1; i<(int)s.size(); ++i)
		{
			if(s[i]==s[i-1])p++;
			else break;
		}
	int n=(int)s.size();
	if(p==n-1)
		{
			cout<<n-1<<endl;
		}
	else if(p)
		{
			cout<<n+(n-p-1)<<endl;
		}
	else cout<<2*n-1<<endl;
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
