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

void ask(int x)
{
	cout<<"+ "<<x<<endl;
}

int a[N];

void mysolve()
{
	cin>>a[1];
	for(int i=2; i<=1000; ++i)
		{
			ask(1),cin>>a[i];
			if(a[i]==a[1])
				{
					cout<<"! "<<max(a[1],i-1)<<endl;
					return;
				}
		}
	int x;
	int p=1000;
	for(int i=1; i<=1000; ++i)
		{
			ask(1000);
			cin>>x;
			p+=1000;
			for(int j=1; j<=1000; ++j)if(a[j]==x)
					{
						cout<<"! "<<p-j<<endl;
					}
		}

}

int32_t main()
{
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
