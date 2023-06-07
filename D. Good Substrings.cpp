#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;
const int mod = 998244353;

int ch[N<<2][26];
int tot;

void mysolve()
{
	string s,t;
	cin>>s>>t;
	int k;
	cin>>k;
	int ans=0;
	for(int i=0; i<(int)s.size(); ++i)
		{
			int res=0;
			int p=0;//p与tot初始值相同
			for(int j=i; j<(int)s.size(); ++j)
				{
					int c=s[j]-'a';
					if(t[c]=='0')res++;
					if(res>k)break;
					if (!ch[p][c])
						{
							ch[p][c] = ++tot;
							ans++;
						}
					p = ch[p][c];
				}
		}
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	//cin >> t;
	//read(t);
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

