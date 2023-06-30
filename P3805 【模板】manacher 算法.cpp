#include <bits/stdc++.h>
using namespace std;
#define ll               long long
int ans = 0;
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
			ans = max(ans, d[i]);
		}
	return d;
}

void mysolve()
{
	string s;
	cin >> s;
	vector<int>d = manacher(s);
	cout << ans << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
