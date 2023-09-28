#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define endl             "\n"
const int N = 1e7 + 10;

vector<int> pre_nxt(string s)//本质是求s自己的z函数
{
	int len = (int)s.size();
	vector<int>p(len);
	p[0] = len; //有时为0，有时为n
	for (int i = 1, l = 0, r = 0; i < len; ++i)//[l,r]是与s前缀匹配的一段
		{
			if (i <= r && p[i - l] < r - i + 1)p[i] = p[i - l];//[i,r]区间内对称的是[i-l,r-l],如果p[i-l]的匹配不超过已知区间，<直接更新，>=需要讨论
			else
				{
					int j = max(0, r - i + 1);
					while (j + i < len && s[j] == s[i + j])++j; //暴力匹配
					p[i] = j;
				}
			if (p[i] + i - 1 > r)l = i, r = i + p[i] - 1;//维护[l,r]使r尽可能大
		}
	return p;
}

vector<int> exkmp(string a, string b)
{
	vector<int>nxt = pre_nxt(a);

	int len = (int)b.size();
	vector<int>p(len);

	for (int i = 0; i < len && i < (int)a.size(); ++i) //p[0]需要暴力
		{
			if (b[i] == a[i])++p[0];
			else break;
		}

	for (int i = 1, l = 0, r = 0; i < len; ++i)//遍历匹配串b
		{
			if (i <= r && nxt[i - l] < r - i + 1)p[i] = nxt[i - l];//取的是模板串的nxt
			else
				{
					int j = max(0, r - i + 1);
					while (i + j < len && a[j] == b[i + j])++j;//j指向模板串，i+j指向匹配串
					p[i] = j;
				}
			if (i + p[i] - 1 > r)l = i, r = i + p[i] - 1;
		}
	return p;
}

vector<int> prefix(string s)
{
	vector<int>p((int)s.size() + 1);
	p[0] = 0;
	for (int i = 1; i < (int)s.size(); ++i)
		{
			int j = p[i - 1];
			while (j && s[i] != s[j])j = p[j - 1]; //找到匹配的最长前缀长度j
			if (s[i] == s[j])++j;
			p[i] = j;
		}
	return p;
}

int d[N];

void kmp(string a, string b) //a模板串，b匹配串
{
	vector<int>p = prefix(b); //先求匹配串的前缀函数

	int j = 0;//j指针指向b字符串
	for (int i = 0; i < (int)a.size(); ++i)
		{
			while (j && a[i] != b[j])j = p[j - 1];//找到当前匹配的最长长度
			if (a[i] == b[j])++j;
			if (j == (int)b.size())//j指向'\0',匹配成功
				{
					d[i]++;
				}
		}
}

string s, t1, t2;

void mysolve()
{
	cin >> t1 >> t2 >> s;
	int n = (int)s.size();
	for (int i = 0; i < n; ++i)d[i] = 0;
	vector pf = exkmp(t1, s);
	reverse(t1.begin(), t1.end()), reverse(s.begin(), s.end());
	vector pb = exkmp(t1, s);
	reverse(pb.begin(), pb.end());
	reverse(s.begin(), s.end());
	kmp(s, t2);
	for (int i = 1; i < n; ++i)d[i] += d[i - 1];
	int len1 = (int)t1.size(), len2 = (int)t2.size(), len = len1 + len2;
	ll ans = 0;
	for (int i = len - 1; i < n; ++i)
		{
			int r = i, l = i - len + 1;
			if (pb[r] + pf[l] >= len1)
				{
					int mr = min(r, l + len2 + pf[l] - 1), ml = max(r - pb[r], l + len2 - 1);
					ans += d[mr] - d[ml - 1];
				}
		}
	cout << ans << endl;
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
