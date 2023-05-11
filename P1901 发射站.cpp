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
const int N = 3e6 + 10;
int ans[N];
int a[N];
void mysolve()
{
	stack<pii>s;
	int n;
	cin>>n;
	int h;
	for(int i=1; i<=n; ++i)
		{
			cin>>h>>a[i];
			if(!s.empty())
				{
					while(!s.empty()&&h>s.top().first)
						{
							ans[i]+=a[s.top().second];
							s.pop();
						}
					if(!s.empty()&&h==s.top().first)a[s.top().second]+=a[i];
					else
						{
							if(!s.empty())
								{
									ans[s.top().second]+=a[i];
								}
							s.push({h,i});
						}
				}
			else
				{
					s.push({h,i});
				}
		}
	cout<<*max_element(ans+1,ans+1+n)<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	//cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
