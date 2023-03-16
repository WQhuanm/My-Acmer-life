#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

//double 型memset最大127，最小128
//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 1e5 + 10;
int p[N];
int main()
{
	int t;
	cin >> t;
	while (t--)
		{
			int n;
			string s;
			cin >> n >> s;
			p[0] = 0;
			for (int i = 1; i < (int)s.size(); ++i)
				{
					int j = p[i - 1];
					while (s[j] != s[i] && j > 0)j = p[j - 1];
					if (s[j] == s[i])j++;
					p[i] = j;
				}
			//从0开始，所有num最后下标是n-1
			int num = n - 1;
			int ans = 0;
			while (num >= 0)
				{
					ans++;
					if (!p[num])num--;
					else
						{
							int tmp = p[num];
							while (tmp * 2 > num + 1 && tmp > 0)tmp = p[tmp - 1];
							num -= tmp;
						}
				}
			cout << ans << endl;
		}
	return 0;
}
