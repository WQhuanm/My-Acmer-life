#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define ll               long long
#define endl             "\n"
#define INF 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define eps 1e-8
#define int              long long
//double 型memset最大127，最小128
//---------------------------------------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------------------------------------//
const int mod = 998244353;
const int N = 3e5 + 10;

int n, q;
int cnt[N], b[N];
string s;

void mysolve()
{
	cin >> n >> q >> s;
	s = '$' + s;
	bool fl = 0;
	for (int i = n; i; --i)
		{
			if (s[i] == 'B')b[i] = b[i + 1] + (fl ? -1 : 1);
			else b[i] = b[i + 1] + (fl ? 1 : -1);
			cnt[i] = cnt[i + 1] ;
			if (s[i] == 'A')cnt[i]++, fl ^= 1;
		}
	int l, r, tl, tr, ans = 0;
	string x;
	while (q--)
		{
			cin >> tl >> tr >> x;
			reverse(x.begin(), x.end());
			int k = (int)x.size();
			ll tmp = 0;
			for (int i = 0; i < k; ++i)if (x[i] == '1')tmp += 1ll << i;
			l = min((ans ^ tl) % n + 1, (ans ^ tr) % n + 1), r = max((ans ^ tl) % n + 1, (ans ^ tr) % n + 1);
			fl = (cnt[l] - cnt[r + 1]) & 1;
			ll m = 1ll << k;
			ans = (((fl ? -tmp : tmp) % m + m) % m + ((cnt[r + 1] & 1 ? -(b[l] - b[r + 1]) : b[l] - b[r + 1]) % m + m) % m) % m;
			string res;
			for (int i = 0; i < k; ++i)
				{
					if ((ans >> i) & 1)res += '1';
					else res += '0';
				}reverse(res.begin(),res.end());
			cout << res << endl;
		}
}

int32_t main()
{
	//	freopen("in.in", "r", stdin);
	//	freopen("out.out", "w", stdout);
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
