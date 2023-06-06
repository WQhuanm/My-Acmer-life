#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
const int N = 1e4 + 10;
bool vis[N];
int ou[N];
void oula(int n)
{
	for(int i=2; i<=n; ++i)
		{
			if (!vis[i])
				{
					vis[i] = 1;
					ou[++ou[0]] = i;//ou[0]是目前素数个数
				}
			for (int j = 1; j <= ou[0] && 1ll*i*ou[j]<= n; ++j)
				{
					vis[i * ou[j]] = 1;//每个数由其最大质因子筛去
					if (i % ou[j] == 0)break;//避免重复筛去(i*ou[j+1]=k*ou[j]*ou[j+1]=t*ou[j+1]),后面自然会出现t帮忙筛去这个t*ou[j+1]
				}
		}
}

void mysolve()
{
	int a,b;
	cin>>a>>b;
	if(abs(a-b)==1)
		{
			cout<<-1<<endl;
			return;
		}
	if(__gcd(a,b)==1)
		{
			int x=abs(a-b);
			int ans=inf;
			for(int i=1; i<=ou[0]&&1ll*ou[i]*ou[i]<=x; ++i)
				{
					if(x%ou[i]==0)
						{
							ans=min(ans,ou[i]-a%ou[i]);
							while(x%ou[i]==0)x/=ou[i];
						}
				}
			if(x>1)	ans=min(ans,x-a%x);
			cout<<ans<<endl;
		}
	else cout<<0<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	oula(1e4);
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

