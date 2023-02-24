#include <bits/stdc++.h>
using namespace std;
#define ll     long long
//#define int ll
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF

const int N = 3e6 + 10;
int n, mod;
ll inv[N];
int32_t main()
{
	cin >> n >> mod;
	inv[1] = 1;
	for (int i = 2; i <= n; ++i)inv[i] = (mod - mod / i) * inv[mod % i] % mod;//（mod-mod/i)是为了保证逆元为正数，反正mod p加上p也不影响
	for (int i = 1; i <= n; ++i)printf("%lld\n", inv[i]);//毒瘤题不让我用cout
	return 0;
}
