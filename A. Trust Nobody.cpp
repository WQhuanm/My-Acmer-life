#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 2e5 + 10;
int a[N];
void mysolve()
{
	int n;
	cin>>n;
	for(int i=1; i<=n; ++i)cin>>a[i];
	sort(a+1,a+1+n);
	int cnt=0,p=-1;
	for(int i=1; i<=n; ++i)
		{
			if(a[i]==p)cnt++;
			else
				{
					if(n-cnt>=a[i])cnt++,p=a[i];//记录真话
					else break;
				}
		}
	if(n-cnt>=p)cout<<n-cnt<<endl;
	else cout<<-1<<endl;
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
