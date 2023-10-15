#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 3e5 + 10;

int one[N], zero[N];
int n;
void add_one(int x, int w)
{
	if (x <= 0)return;
	for (int i = x; i <= n; i += i & -i)one[i] += w;
}
int ask_one(int x)
{
	if (x <= 0)return 0;
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += one[i];
	return ans;
}

void add_zero(int x, int w)
{
	if (x <= 0)return;
	for (int i = x; i <= n; i += i & -i)zero[i] += w;
}
int ask_zero(int x)
{
	if (x <= 0)return 0;
	int ans = 0;
	for (int i = x; i; i -= i & -i)ans += zero[i];
	return ans;
}

void mysolve()
{
	string s;
	cin >> s;
	n = (int)s.size();
	for (int i = 0; i <= n; ++i)zero[i] = one[i] = 0;
	s = '$' + s;
	int len = 0;
	for (auto v : s)
		{
			if (v == '+')len++;
			else if (v == '-')
				{
					int w = ask_one(len) - ask_one(len - 1);
					add_one(len, -w);
					if (len - 1 >= 1)add_one(len - 1, w);

					w = ask_zero(len) - ask_zero(len - 1);
					add_zero(len, -w);
					len--;
				}
			else if (v == '1')
				{
					if (ask_zero(len))return cout << "NO" << endl, void();
					add_one(len, 1);
				}
			else if (v == '0')
				{
					int w = ask_one(len) - ask_one(len - 1);
					if (w || len <= 1)return cout << "NO" << endl, void();
					add_zero(len, 1);
				}
		}
	cout << "YES" << endl;
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
	system("pause");
	return 0;
}
