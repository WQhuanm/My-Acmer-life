#include <bits/stdc++.h>
using namespace std;
#define ll     long long
#define int ll
const int N = 1e5 + 10;

int a[N];
struct tree//我们以结构体来存储一颗树
{
	int l, r;//l,r表示该节点的区间
	ll sum, add;//sum表示区间和，add为懒惰标记
} t[N * 4 + 2]; //如果维护n个节点的区间，建立完整的二叉树大概需要4*n个树节点

void build(int l, int r, int p)
{
	t[p].l = l, t[p].r = r; //首先存储节点p的区间
	if (l == r)//如果区间只有一个点
		{
			t[p].sum = a[l];//sum就是这个点的值
			return;
		}
	//否则继续二分遍历
	int mid = l + ((r - l) >> 1);// 移位运算符的优先级小于加减法，所以加上括号,	// 如果写成 (l + r) >> 1 可能会超出 int 范围
	build(l, mid, 2 * p);
	build(mid + 1, r, 2 * p + 1);
	t[p].sum = t[2 * p].sum + t[2 * p + 1].sum;//回来后区间和就等于儿子们的区间和之和
}

void lazy(int p)
{
	if (t[p].l == t[p].r)t[p].add = 0;//如果该区间只有一个点，毫无疑问他没有儿子，直接删除他的懒惰标记
	if (t[p].add)//如果懒惰区间不为0，更新儿子信息
		{
			//对儿子们的区间和更新
			t[2 * p].sum += t[p].add * (t[2 * p].r - t[2 * p].l + 1);
			t[2 * p + 1].sum += t[p].add * (t[2 * p + 1].r - t[2 * p + 1].l + 1);
			//每次更新区间就更新这个区间的懒惰标记，这样儿子访问子代时其懒惰区间才可以正常使用
			t[2 * p].add += t[p].add;
			t[2 * p + 1].add += t[p].add;
			//最后重置p的懒惰标记（他就是为子代存在的，而我们已经更新完子代了）
			t[p].add = 0;
		}
}

void addupdate(int l, int r, int p, ll z)
{
	if (l <= t[p].l && t[p].r <= r)//如果当前p的区间是目标区间的子集，更新其区间值和懒惰标记就可以返回了
		{
			t[p].sum += z * (t[p].r - t[p].l + 1);
			t[p].add += z;
			return;
		}
	//如果不是全部属于目标区间，访问子代前先更新子代，清空自己的懒惰标记
	lazy(p);
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	if (l <= mid)addupdate(l, r, 2 * p, z);//如果[t[p].l,mid]有一部分属于目标区间，更新[l,mid]
	if (r > mid)addupdate(l, r, 2 * p + 1, z);//[mid+1,t[p].r]同理
	t[p].sum = t[2 * p].sum + t[2 * p + 1].sum;//回来后重新更新t[p].sum(因为子代已经更新）
}

ll ask(int l, int r, int p)
{
	if (l <= t[p].l && t[p].r <= r)return t[p].sum;//属于子集直接返回
	lazy(p);//如果不是全部属于目标区间，访问子代前先更新子代，清空自己的懒惰标记
	int mid = t[p].l + ((t[p].r - t[p].l) >> 1);
	ll ans = 0;//ans累积属于目标区间的和
	if (l <= mid)ans += ask(l, r, 2 * p);
	if (r > mid)ans += ask(l, r, 2 * p + 1);
	return ans;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)cin >> a[i];
	build(1, n, 1);//每次都从根节点p=1建树
	int b, l, r, k;
	while (m--)
		{
			cin >> b >> l >> r;
			if (b == 1)
				{
					cin >> k;
					addupdate(l, r, 1, k);//更新，查询也都成根节点p=1开始
				}
			else if (b == 2)
				{
					cout << ask(l, r, 1) << endl;//更新，查询也都成根节点p=1开始
				}
		}
	return 0;
}
