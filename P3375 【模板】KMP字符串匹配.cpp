#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

int p[N];
int main()
{
	string a, b;
	cin >> a >> b;
	//前缀函数
	p[0] = 0;
	for (int i = 1; i < (int)b.size(); ++i)
		{
			int j = p[i - 1];
			while (j > 0 && b[i] != b[j])j = p[j - 1];
			if (b[i] == b[j])++j;
			p[i] = j;
		}

	//kmp
	int j = 0;//j指针指向b字符串
	for (int i = 0; i < (int)a.size(); ++i)//i指针指向a字符串
		{
			while (j > 0 && a[i] != b[j])j = p[j - 1];//如果不相等，跳跃，当然j>0(即j指针不是指向b串第一个字符时），i与j是当前比对的位置，我们跳跃是前面成功匹配的j-1部分
			if (a[i] == b[j])++j;//出来成功匹配，j往前
			if (j == (int)b.size())cout << i - j + 2 << endl;//如果j为b长度，说明符合，输出a匹配b的第一个位置，继续往下寻找，不需要重置j，因为下一次进入，while比较是j指向\0,自然会跳跃
		}
	for (int i = 0; i < (int)b.size(); ++i)
		{
			cout << p[i];
			if (i == (int)b.size() - 1)cout << endl;
			else cout << ' ';
		}
	return 0;
}
