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
int l[N],r[N];
void mysolve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1; i<=n; ++i)cin>>l[i];
	for(int i=1; i<=n; ++i)cin>>r[i];
	int cnt=0,sum=0;
	int ans=INF;
	for(int i=1; i<=n; ++i)
		{
			int len=r[i]-l[i]+1;//连续格子数
			sum+=len;
			if(sum>=k)
				{
					int tmp=sum-k;
					int res=r[i]-tmp+2*(i)-min(tmp,cnt);//只要大于k，就尝试去减前面记录的单独一格
					ans=min(ans,res);
					//不跳出，因为有可能前面累加的都是1，后面可能遇到更好的
				}
			if(len==1)cnt++;//记录单独格子
		}
	if(ans==INF)cout<<-1<<endl;
	else
		cout<<ans<<endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t=1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
