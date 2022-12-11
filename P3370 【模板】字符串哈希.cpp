#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

ull base = 131;

ull hashs(string a)
{
	ull ans = 0;
	for (int i = 0; i < (int)a.size(); ++i)
		{
			ans = (ans * base + a[i] );
		}
	return ans;
}

int main()
{
	set<ull>st;//set存储出现过的哈希值
	int n;
	cin >> n;
	string a;
	for (int i = 1; i <= n; ++i)
		{
			cin >> a;
			ull tmp = hashs(a);
			st.insert(tmp);
		}
	cout << st.size() << endl;//返回存储过的哈希值个数（就是不同字符串个数）

}
