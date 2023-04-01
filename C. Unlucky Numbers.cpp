#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

int check(int x)
{
	set<int>s;
	while (x)
		{
			s.insert(x%10);
			x/=10;
		}
	return (*s.rbegin()-*s.begin());
}
void mysolve()
{
	ll l,r;
	cin>>l>>r;
	ll ans=l,p=1;
	for (int i=1; i<=19; ++i)
		{
			for (int x=0; x<10; ++x)
				{
					int tmp=l/p*p+(p-1)/9*x;//l/p*p是先使前面i位变为0，再用(p-1)/9*x保证前面i位是相同的
					if (tmp>=l&&tmp<=r&&check(tmp)<check(ans))ans=tmp;
					tmp=r/p*p+(p-1)/9*x;
					if (tmp>=l&&tmp<=r&&check(tmp)<check(ans))ans=tmp;
				}
			p*=10;
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

