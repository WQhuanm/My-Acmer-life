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
const int N = 3e6 + 10;
int a[N];
void mysolve()
{
	stack<pii>s;
	int n,x;
	cin>>n;
	for(int i=1; i<=n; ++i)
		{
			cin>>x;
			while(!s.empty()&&s.top().first<x)
				{
					a[s.top().second]=i;
					s.pop();
				}
			s.push({x,i});
		}
	for(int i=1; i<=n; ++i)cout<<a[i]<<" \n"[i==n];
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
