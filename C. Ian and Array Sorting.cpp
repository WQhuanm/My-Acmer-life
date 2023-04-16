#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define int ll
#define endl             "\n"
const int N = 3e5 + 10;
int a[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i];
	if(n&1)cout<<"YES"<<endl;
	else
		{
			for(int i=1; i<n-1; ++i)
				{
					int tmp=a[i+1]-a[i];
					a[i+1]-=tmp,a[i+2]-=tmp;
				}
			if(a[n]>=a[n-1])cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
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
