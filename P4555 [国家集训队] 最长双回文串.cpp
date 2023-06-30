#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
const int N = 3e5 + 10;
const int mod = 998244353;

vector<int> manacher(string &tmp)
{
	string s;
	for (int i = 0; i < (int)tmp.size(); ++i)s += "$", s += tmp[i];
	s += "$";
	int len = (int)s.size();
	vector<int>d(len);
	for (int i = 0, l = 0, r = -1; l < len; ++i)
		{
			int k = (i > r ? 1 : min(d[l + r - i], r - i + 1));
			while (0 <= i - k && i + k < len && s[i - k] == s[i + k])k++;
			d[i] = --k;
			if (i + k > r)l = i - k, r = i + k;
		}
	return d;
}

int l[N], r[N];

void mysolve()
{
	string s;
	cin >> s;
	vector<int>d = manacher(s);
	for (int i = 0; i < (int)s.size(); ++i)
		{
			int p = i + d[2 * i + 1] / 2;
			l[p] = max(l[p], d[2 * i + 1]);
			p = i + d[2 * i] / 2 - 1;
			l[p] = max(l[p], d[2 * i]);

			p = i - d[2 * i + 1] / 2;
			r[p] = max(r[p], d[2 * i + 1]);
			p = i - d[2 * i] / 2 ;
			r[p] = max(r[p], d[2 * i]);
		}

	for (int i = (int)s.size() - 2; ~i; --i)l[i] = max(l[i], l[i + 1] - 2);
	for (int i = 1; i < (int)s.size(); ++i)r[i] = max(r[i], r[i - 1] - 2);
	int ans = 0;
	for (int i = 0; i < (int)s.size() - 1; ++i)
		{
			ans = max(ans, l[i] + r[i + 1]);
		}

	cout << ans << endl;
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
