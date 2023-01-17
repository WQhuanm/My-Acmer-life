#include <bits/stdc++.h>
using namespace std;
#define ll     long long
typedef unsigned long long ull;
typedef pair<long long, long long> pll;

//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int INF = 0x3f3f3f3f;         //int型的INF
const ll llINF = 0x3f3f3f3f3f3f3f3f;//ll型的llINF
const int N = 2e5 + 10;

bool mp[30][30];
bool flag;

void dfs(int j)
{
	if (flag)return;
	if (j == 12)
		{
			flag = 1;
			return;
		}
	for (int i = 0; i < 26; ++i)
		{
			if (mp[j][i])
				{
					mp[j][i] = 0;
					dfs(i);
					if (flag)return ;
					mp[j][i] = 1;
				}
		}
}

int main()
{
	string s;
	while (cin >> s)
		{
			if (s[0] != '0')
				{
					int a = s[0] - 'a', b = s[s.size() - 1] - 'a';
					mp[a][b] = 1;
				}
			else
				{
					flag = 0;
					dfs(1);
					if (flag)cout << "Yes." << endl;
					else cout << "No." << endl;
					memset(mp, 0, sizeof(mp));
				}

		}

	return 0;
}
