#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int ll
const int N = 20;
int dp[N][2000],bit[N];
map<vector<int>,int>mp;
int cnt;

//状态打表
//int ans;
//
//void dfs(int i,int cnt,int sum)//i为出现i次，cnt录入几个不同的数字，sum为选的i的和
//{
//	if(sum>18)return;
//	if(cnt>10)return;
//	if(i==19)
//	{
//		ans++;
//		return;
//	}
//	for(int j=0; j<=18/i; ++j)//j为出现i次有j个数
//	{
//		dfs(i+1,cnt+j,sum+j*i);
//	}
//}
//
//void mysolve()
//{
//	dfs(1,0,0);
//	cout<<ans<<endl;
//}

int dfs(int len,vector<int>a,bool limit,bool zero)
{
	if(!len)return *max_element(a.begin(),a.end());
	vector<int>p(20);
	for(auto v:a)if(v)p[v]++;//将a数组状态转为每个出现次数有几个数字的状态，用map存储对应的数组
	if(!mp[p])mp[p]=++cnt;
	int sta=mp[p];
	if(!limit&&dp[len][sta]!=-1)return dp[len][sta];
	int ans=0;
	int top=limit?bit[len]:9;
	for(int i=0; i<=top; ++i)
		{
			vector<int>tmp=a;
			if(i||len==1||!zero)tmp[i]++;//zero判断前导零问题
			ans+=dfs(len-1,tmp,limit&&i==top,(!i)&&zero);
		}
	if(!limit)return dp[len][sta]=ans;//存储无限制下的状态
	return ans;
}

int cal(int x)//把数字x按位存储到数组
{
	if(x<0)return 0;
	if(x==0)return 1;//可能要特判0与负数的贡献
	int len=0;
	while(x)bit[++len]=x%10,x/=10;
	return dfs(len,vector<int>(10),1,1);
}

void mysolve()
{
	int l,r;
	cin>>l>>r;
	cout<<cal(r)-cal(l-1)<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t=1;
	cin >> t;
	//read(t);
	memset(dp,-1,sizeof(dp));
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}

