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

int n, m;
int a[N], b[N], pa[N], pb[N];
vector<int> ans_a, ans_b;

void mysolve()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i], pa[a[i]] = i;
	for (int i = 1; i <= m; ++i)cin >> b[i], pb[b[i]] = i;

	for (int i = 1; i <= n; ++i)if (a[i] != i)
			{
				int nowa = pa[i];
				int A = i - 1, B = nowa - i - 1, C = n - nowa;
				ans_a.push_back(nowa);
				ans_a.push_back(C + A + 2);
				ans_a.push_back(B + C + 2);
				pa[a[i]] = nowa;
				swap(a[i], a[nowa]);
			}
	for (int i = 1; i <= m; ++i)if (b[i] != i)
			{
				int now = pb[i];
				int A = i - 1, B = now - i - 1, C = m - now;
				ans_b.push_back(now);
				ans_b.push_back(C + A + 2);
				ans_b.push_back(B + C + 2);
				pb[b[i]] = now;
				swap(b[i], b[now]);
			}
	if ((int)(ans_a.size() - ans_b.size()) % 2 == 0)
		{
			while (ans_a.size() < ans_b.size())ans_a.push_back(1), ans_a.push_back(n);
			while (ans_a.size() > ans_b.size())ans_b.push_back(1), ans_b.push_back(m);
		}
	else
		{
			if (n & 1)for (int i = 1; i <= n; ++i)ans_a.push_back(1);
			else if (m & 1)for (int i = 1; i <= m; ++i)ans_b.push_back(1);
			else
				{
					cout << -1 << endl;
					return;
				}
			while (ans_a.size() < ans_b.size())ans_a.push_back(1), ans_a.push_back(n);
			while (ans_a.size() > ans_b.size())ans_b.push_back(1), ans_b.push_back(m);
		}
	cout << (int)ans_a.size() << endl;
	for (int i = 0; i < (int)ans_a.size(); ++i)cout << ans_a[i] << " " << ans_b[i] << endl;
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
