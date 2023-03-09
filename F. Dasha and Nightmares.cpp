#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int N = 2e5 + 10;

int a[N], b[N];
int mp[1 << 26];
int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	string s;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		{
			cin >> s;
			for (auto &c : s)
				{
					a[i] |= 1 << (c - 'a'); //或运算记录是否出现
					b[i] ^= 1 << (c - 'a'); //异或运算计算出现奇偶次数
				}
		}
	ll ans = 0;
	for (int c = 0; c < 26; ++c)
		{
			int tmp = (1 << 26) - 1 - (1 << c); //(1<<26)-1使得前25位都是1，-(1<<c)使得只有第c位不是1，用于后面异或匹配奇偶
			for (int i = 1; i <= n; ++i)
				{
					if (~(a[i] >> c) & 1) //如果第i串没有第c个字母
						{
							mp[b[i]]++;
							ans += mp[tmp ^ b[i]]; //tmp^b[i]就是与i串每个字母奇偶性匹配的哈希值
						}
				}
			//每次匹配的前提是缺少同一个字母c，所有缺少这个字母的匹配统计后，哈希匹配数要清空
			for (int i = 1; i <= n; ++i)if (~(a[i] >> c) & 1)mp[b[i]] = 0;
		}
	cout << ans << endl;
	return 0;
}
