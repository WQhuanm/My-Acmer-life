#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-8
#define int              long long
typedef pair<int, int> pii;
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int N = 3e5 + 10;
const int mod = 998244353;
int n;
int a[N], p[N];

void exgcd(int a, int b, int &x, int &y)//&直接修改值
{
	if (!b)x = 1, y = 0;
	else
		{
			exgcd(b, a % b, y, x);//x继承了深层的y,y就继承深层的x，y再减去(a/b)*y2即-(a/b)*x即可
			y -= (a / b) * x;
		}
}

ll CRT(int k, int *a, int *p)//x≡a[i]%p[i]
{
	ll n = 1, ans = 0;
	for (int i = 1; i <= k; ++i)n *= p[i];
	for (int i = 1; i <= k; ++i)
		{
			ll m = n / p[i], x, y;
			exgcd(m, p[i], x, y);
			x = (x + p[i]) % p[i];//求出m及其逆元x，答案就是m*x*a[i]求和
			ans = (ans + m * x * a[i]) % n;
		}
	return ans;
}

void mysolve()
{
	cin >> n;
	for (int i = 1; i <= n; ++i)cin >> p[i] >> a[i];
	cout << CRT(n, a, p);
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
