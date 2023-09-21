#include <bits/stdc++.h>
using namespace std;
#define int              long long
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;

int n, k;
struct node
{
	int x, id;
	bool operator<(const node&k)const
	{
		if (x != k.x)return x > k.x;
		else return id < k.id;
	}
} a[N];

void mysolve()
{
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a[i].x, a[i].id = i;
		a[i].x%=k;
		if(!a[i].x)a[i].x=k;
		}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)cout<<a[i].id<<" \n"[i==n];

}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
