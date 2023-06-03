#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
const int N = 3e5 + 10;
const int mod = 998244353;

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

void exgcd(ll a, ll b, ll &x, ll &y)//&直接修改值
{
	if (!b)x = 1, y = 0;
	else
		{
			exgcd(b, a % b, y, x);//x继承了深层的y,y就继承深层的x，y再减去(a/b)*y2即-(a/b)*x即可
			y -= (a / b) * x;
		}
}

vector<int>v;
ll ans=INF;
void dfs(int i,ll res,ll sum)//dfs暴力枚举因子组合
{
	if(i==(int)v.size())
		{
			ll a=res,b=sum/res,x,y;
			exgcd(a, b, x, y);
			x = ( -x + b) % b;//保证逆元为正数，这里x取的是-x（-ax），但是要求-ax>0
			if(x)ans=min(ans,x*a);
			else ans=min(ans,sum);//特判res=1，此时模数为1，x必为0
			return;
		}
	dfs(i+1,res*v[i],sum*v[i]);
	dfs(i+1,res,sum*v[i]);
}

void mysolve()
{
	oula(1e4);
	int n,x;
	cin>>n;
	map<int,int>mp;
	for(int i=1; i<=n; ++i)
		{
			cin>>x;
			for(int i=1; i<=ou[0]&&1ll*ou[i]<=x; ++i)
				{
					if(x%ou[i]==0)
						{
							int cnt=0;
							while(x%ou[i]==0)cnt++,x/=ou[i];
							mp[ou[i]]=max(mp[ou[i]],cnt);
						}
				}
			if(x>1)
				{
					mp[x]=max(mp[x],1);
				}
		}
	mp[2]++;
	for(auto [k,val]:mp)//求出lcm的因子
		{
			int res=1;
			for(int i=1; i<=val; ++i)res=1ll*res*k;
			v.push_back(res);
		}
	dfs(0,1,1);
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

