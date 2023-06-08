#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-9
#define int              long long
typedef pair<int, int> pii;
inline int read(int &x);
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353,mod2=1e9+7;

void mysolve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	string ans;
	ans+=s[0];
	char c=s[0];
	for(int i=1; i<(int)s.size(); ++i)
		{

			if(c>s[i])ans.push_back(s[i]);
			else if(c==s[i])
				{
					int fl=1;
					string tmp;
					tmp+=c;
					int len=0;
					for(int j=1; j+i<(int)s.size()&&j<i; ++j)
						{
							if(s[j+i]<s[j])
								{
									ans+=tmp+s[j+i];
									i=i+j;
									fl=2;
									break;
								}
							else if(s[j+i]>s[j])
								{
									fl=0;
									break;
								}
							tmp+=s[j+i];
							len++;
						}
					if(!fl)break;
					if(fl==1&&i+len==(int)s.size()-1)break;
					if(fl==1)ans+=tmp,i+=len;
				}
			else break;
			if((int)ans.size()>=k)break;
		}
	while((int)ans.size()<k)ans=ans+ans;
	while((int)ans.size()>k)ans.pop_back();
	cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

inline int read(int &x)
{
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9')ch = getchar();
	while (ch >= '0' && ch <= '9')
		{
			x = x * 10 + ch - '0';
			ch = getchar();
		}
	return x;
}
