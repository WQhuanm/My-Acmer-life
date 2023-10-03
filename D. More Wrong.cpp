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
const int mod = 998244353, Mmod = (ll)1e18 + 31; //(ll)1e18,double浮点数只有15位，1e15后面+的小数会被省略
const int N = 3e5 + 10;

int n;
int solve(int l, int r)
{
	if (l >= r)return l;
	int mid = l + ((r - l) >> 1);
	int ml = solve(l, mid), mr = solve(mid + 1, r);
	int len1, len2;
	cout << "? " << ml << " " << mr << endl;
	cin >> len1;
	if (ml + 1 != mr)
		{
			cout << "? " << ml + 1 << " " << mr << endl;
			cin >> len2;
		}
	else len2 = 0;
	return (len1 == len2 + mr - ml ? ml : mr);
}

void mysolve()
{
	cin >> n;
	int ans = solve(1, n);
	cout << "! " << ans << endl;
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
//	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
