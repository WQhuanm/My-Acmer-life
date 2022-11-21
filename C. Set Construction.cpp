#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

char a[200][200];
void mymin()
{
	map<int, set<int> >mp;//用map存放第i组的set
	memset(a, 0, sizeof(a));
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)cin >> a[i][j];
	for (int i = 1; i <= n; ++i)mp[i].insert(i);//每个集合初始赋值一个元素

	for (int i = 1; i <= n; ++i)for (int j = 1; j <= n; ++j)
			if (a[i][j] == '1')for (auto &k : mp[i])mp[j].insert(k);//=‘1’，说明存在父子关系，继承（遍历子代mp[i]的元素存入mp[j]里面
	for (int i = 1; i <= n; ++i)
		{
			cout << (int)mp[i].size();
			for (auto &k : mp[i])cout << " " << k;
			cout << endl;
		}
}

int main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
		{
			mymin();
		}
	system("pause");
	return 0;
}
