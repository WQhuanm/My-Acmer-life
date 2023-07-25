#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<int, int> pii;
void mysolve()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	s = '$' + s;
	int p = find(s.begin(), s.end(), '1') - s.begin();
	vector<pii>ans;
	for (int i = 1; i <= n; ++i)if (s[i] == '1' && i != p)ans.push_back({p, i});
	vector<int>tmp;
	for (int i = 1; i <= n; ++i)if (i != p)tmp.push_back(i);

	for (int i = (int)tmp.size() - 1; i >= 0; --i)for (int j = 0; j < i; ++j)ans.push_back({tmp[j], tmp[j + 1]});

	int cnt = count(s.begin(), s.end(), '0');

	for (int i = 1; i < p; ++i)ans.push_back({i, p});
	for (int i = cnt; i > p; --i)ans.push_back({p, i});
	cout << (int)ans.size() << endl;
	for (auto [v, k] : ans)cout << v << " " << k << endl;

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
	//	system("pause");
	return 0;
}
