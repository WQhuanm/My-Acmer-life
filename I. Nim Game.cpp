#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long
#define endll            endl<<endl
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
//double 型memset最大127，最小128
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

int t[N],q[N],a[N];
int n;
bool zero;
void update(int x,int w)
{
	for(int i=x; i<=n; i+=i&-i)t[i]+=w;
}
int ask(int x)
{
	int ans=0;
	for(int i=x; i; i-=i&-i)ans+=t[i];
	return ans;
}
void insert(int x)
{
	for(int i=63; ~i; --i)if(x&(1ll<<i))//线性基记得64位是1ll
			{
				if(!q[i])
					{
						q[i]=x;
						return;
					}
				else x^=q[i];
			}
	zero=1;
}
void mysolve()
{
	int m,x;
	cin>>n>>m;
	for(int i=1; i<=n; ++i)cin>>x,update(i,x),update(i+1,-x);
	int op,l,r;
	while(m--)
		{
			cin>>op>>l>>r;
			if(op==1)
				{
					cin>>x;
					update(l,x),update(r+1,-x);
				}
			else
				{
					zero=0;
					for(int i=0; i<64; ++i)q[i]=0;//二进制位0~63全部初始化
					for(int i=l; i<=r; ++i)
						{
							insert(ask(i));//64次都能全部插入，没有异或0，不能则有异或0
							if(zero)break;
						}
					if(zero)cout<<"Yes"<<endl;
					else cout<<"No"<<endl;
				}
		}
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
