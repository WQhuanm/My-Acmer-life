#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define int              long long
const int N=100;
int a[N];//线性基数组
int d[N];//求第k小的数组
bool zero;//判断区间线性基是否存在异或和为0
void insert(int x)
{
	//注意1ll，64位数
	for(int i=63; ~i; --i)if(x&(1ll<<i))//询问x二进制最高位1，显然x的高位1在异或中是不断严格递减的
			{
				if(!a[i])//线性基该位置未被插入即可插入后退出
					{
						a[i]=x;
						return;
					}
				else x^=a[i];
			}
	zero=1;//如果能出来，说明没有插入成功，标记存在区间异或0
}

bool check(int x)
{
	for(int i=63; ~i; --i)if(x&(1ll<<i))//注意1ll，64位数
			{
				if(!a[i])return 0;
				else x^=a[i];
			}
	return 1;
}

int qmax()
{
	int ans=0;
	for(int i=63; ~i; --i)ans=max(ans,ans^a[i]);
	return ans;
}

int qmin()
{
	if(zero)return 0;//特判异或0
	for(int i=0; i<64; ++i)if(a[i])return a[i];
}

int qkth(int k)
{
	if(zero)k--;
	if(!k)return 0;
	int cnt=0;//记录线性基插入几个元素，显然线性基可以异或得到的元素为(2^cnt)-1个,去空集
	for(int i=0; i<=63; ++i)if(a[i])
			{
				d[++cnt]=a[i];
				for(int j=i-1; ~j; --j)if(a[j]&&d[cnt]&(1ll<<j))d[cnt]^=a[j];
			}
	if(k>=(1ll<<cnt))return -1;//注意1ll，64位
	int ans=0;//此时cnt的每一位可以等价看出k的二进制上的每一位，k上为1，表示取该线性基元素
	for(int i=cnt-1; ~i; --i)if(k&(1ll<<i))ans^=d[i];
	return ans;
}

int rankkth(int x)
{
	int cnt=0;//记录线性基插入几个元素，显然线性基可以异或得到的元素为(2^cnt)-1个,去空集
	for(int i=0; i<=63; ++i)if(a[i])
			{
				d[++cnt]=a[i];
				for(int j=i-1; ~j; --j)if(a[j]&&d[cnt]&(1ll<<j))d[cnt]^=a[j];
			}
	int ans=0;
	for(int i=cnt-1; ~i; --i)if(x>=d[i])ans+=(1ll<<i),x^=d[i];
	return ans+zero;
}

void mysolve()
{
	int n,x;
	cin>>n;
	while(n--)
		{
			cin>>x;
			insert(x);
		}
	cout<<qmax()<<endl;
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
