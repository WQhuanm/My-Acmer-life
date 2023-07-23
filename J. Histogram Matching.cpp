#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
typedef pair<int, int> pii;
const int N = 1e5 + 10;

int s[N], a[N];
int n, m;

vector<int> prefix()
{
	vector<int>p(n + 1);
	p[0] = 0;
	for (int i = 1; i < n; ++i)
		{
			int j = p[i - 1];
			while (j && s[i] != s[j])j = p[j - 1]; //找到匹配的最长前缀长度j
			if (s[i] == s[j])++j;
			p[i] = j;
		}
	return p;
}

void mysolve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)cin >> s[i];
	vector p = prefix();
	cin >> m;
	for (int i = 0; i < m; ++i)cin >> a[i];
	deque<int>qt;
	qt.push_front(0);
	stack<pii>tmp;
	while (!qt.empty())
		{
			int u = qt.front();
			qt.pop_front();
			int j = 0, h = a[u] - s[0], q = 0; //j指针指向b字符串

			for (int i = u; i < m; ++i)//a模板串，b匹配串
				{
					if (a[i] == h)continue;
					else if (a[i] < h)
						{
							if (j && i + 1 < m && a[i] - a[i + 1] == s[0] - s[1] && i + n - 1 < m)qt.push_back(i);
							continue;
						}
					while (j && a[i] - h != s[j])j = p[j - 1]; //找到当前匹配的最长长度
					if (!j)h =  a[i] - s[j], j++, q = i;
					else if (a[i] - h == s[j])++j;
					while (!qt.empty() && j && i - qt.back() < n)qt.pop_back();
					if (j == n)//j指向'\0',匹配成功
						{
							cout << "YES" << endl;
							for (int k = q; k <= i; ++k)if (a[k] > h)cout << k + 1 << " ";
							return;
						}
				}
		}
	cout << "NO" << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
