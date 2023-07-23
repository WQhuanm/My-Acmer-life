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
const int N = 1e6 + 10;
const int mod = 998244353;
const int mod2 = 1e9 + 7;

int base = 131, base2 = 1331; //p进制减少哈希碰撞
ll mi[N], b[N], b2[N], mi2[N]; //存储hash值

//减法记得取模
inline void  mhash(string s)
{
	b[0] = s[0] % mod;
	for (int i = 2; i < (int)s.size(); i += 2)b[i] = (b[i - 2] * base % mod + s[i]) % mod;
	b[1] = s[1] % mod;
	for (int i = 3; i < (int)s.size(); i += 2)b[i] = (b[i - 2] * base % mod + s[i]) % mod;

	b2[0] = s[0] % mod;
	for (int i = 2; i < (int)s.size(); i += 2)b2[i] = (b2[i - 2] * base2 % mod2 + s[i]) % mod2;
	b2[1] = s[1] % mod;
	for (int i = 3; i < (int)s.size(); i += 2)b2[i] = (b2[i - 2] * base2 % mod2 + s[i]) % mod2;

}

int hash1(int l, int r)//even
{
	r--;
	int ans = (b[r] - (l - 2 < 0 ? 0 : b[l - 2]) * mi[(r - l + 2) / 2] % mod + mod) % mod * mi[l / 2] % mod;
	ans = (ans + (l - 2 < 0 ? 0 : b[l - 2])) % mod;
	return ans;
}

int hash2(int l, int r)//odd
{

	int ans = (b[r] - (l - 2 < 0 ? 0 : b[l - 2]) * mi[(r - l + 2) / 2] % mod + mod) % mod * mi[l / 2] % mod;
	ans = (ans + (l - 2 < 0 ? 0 : b[l - 2])) % mod;
	return ans;
}

int hash3(int l, int r)//even
{
	r--;
	int ans = (b2[r] - (l - 2 < 0 ? 0 : b2[l - 2]) * mi2[(r - l + 2) / 2] % mod2 + mod2) % mod2 * mi2[l / 2] % mod2;
	ans = (ans + (l - 2 < 0 ? 0 : b2[l - 2])) % mod2;
	return ans;
}

int hash4(int l, int r)//odd
{

	int ans = (b2[r] - (l - 2 < 0 ? 0 : b2[l - 2]) * mi2[(r - l + 2) / 2] % mod2 + mod2) % mod2 * mi2[l / 2] % mod2;
	ans = (ans + (l - 2 < 0 ? 0 : b2[l - 2])) % mod2;
	return ans;
}

void mysolve()
{
	int n;
	string s;
	cin >> n >> s;
	mhash(s);
	map<pii, int>cnt;
	set<pair<pii, pii>>st;
	for (int i = 0; i < (int)s.size(); ++i)
		{
			int a = 0, b = 0, a2 = 0, b2 = 0;
			if (i & 1)a = hash2(i, n - 1), a2 = hash4(i, n - 1);
			else a = hash1(i, n - 1), a2 = hash3(i, n - 1);
			cnt[ {a, a2}]++;
			if (i + 1 < n)
				{
					if ((i + 1) & 1)b = hash2(i + 1, n - 1), b2 = hash4(i + 1, n - 1);
					else b = hash1(i + 1, n - 1), b2 = hash3(i + 1, n - 1);
				}
			else
				{
					b = hash1(0, n - 1), b2 = hash3(0, n - 1);
				}
			st.insert({{a, a2}, { b, b2}});
		}
	ll ans = n * n;
	for (pair<pii, pii> v : st)
		{
			ans -= cnt[v.first] * cnt[v.second];
		}
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	int t = 1;
	//	cin >> t;
	mi[0] = 1; //预处理幂
	for (int i = 1; i <= N - 10; ++i)mi[i] = mi[i - 1] * base % mod;

	mi2[0] = 1; //预处理幂
	for (int i = 1; i <= N - 10; ++i)mi2[i] = mi2[i - 1] * base2 % mod2;
	while (t--)
		{
			mysolve();
		}
	system("pause");
	return 0;
}
