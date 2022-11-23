#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N = 2e5 + 100;

ll n, a, b;
struct node
{
	ll s, w;
};

vector<node>arr[N];

set<ll>st;

bool flag;//flag标记有没有这样的路径
void dfsa(ll to, ll fr, ll sum)//to去哪里，fr从哪里去，sum，目前异或和
{
	if (to == b)return;//到了b，我不去（包括去b的这路径的异或和我也不存，因为从b出发自然会包括
	st.insert(sum);//存入，这样也把最开始（a,0,0）的0存入（因为你异或和为0肯定是一条成功路径
	for (auto &k : arr[to])//遍历
		{
			if (k.s == fr)continue;//如果子节点是fr（从哪里来），就下一个点（不然就逆回去了）
			dfsa(k.s, to, k.w ^ sum);//其余点全dfs
		}
}

void dfsb(ll to, ll fr, ll sum)
{
	if (!flag)return;//剪枝，找到就离开
	if (st.count(sum) && to != b)//必须to（去的地方不是b才判断），set存在这个数，count返回1
		{
			flag = 0;
			return;
		}
	for (auto &k : arr[to])
		{
			if (k.s == fr)continue;
			dfsb(k.s, to, k.w ^ sum);
		}
}

void mymin()
{
	cin >> n >> a >> b;
	st.clear();
	for (int i = 1; i <= n; ++i)arr[i].clear(); //多案例要清空
	ll u, v, w;
	for (int i = 1; i < n; ++i)
		{
			cin >> u >> v >> w;
			arr[u].push_back({v, w});
			arr[v].push_back({u, w});
		}

	flag = 1;
	dfsa(a, 0, 0);
	dfsb(b, 0, 0);
	if (!flag)cout << "YES" << endl;
	else cout << "NO" << endl;
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
