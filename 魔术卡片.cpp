#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"

int ask(int x)
{
	int ans=0;
	for (int i=0; i<8; ++i)if ((x>>i)&1)ans++;
	return ans;
}
void mysolve()
{
	int n;
	cin>>n;
	vector<int>v[10];
	int cnt=1;
	for (int i=0; i<(1<<8); ++i)
		{
			if (ask(i)==4)//只有4个1
				{
					for (int j=0; j<8; ++j)if ((i>>j)&1)v[j].push_back(cnt);//j位有1，j卡牌有数cnt
					if (++cnt>n)break;
				}
		}
	cout<<8<<endl;
	for (int i=0; i<8; ++i)
		{
			cout<<(int)v[i].size();
			for (int j=0; j<(int)v[i].size(); ++j)cout<<" "<<v[i][j];
			cout<<endl;
		}
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
