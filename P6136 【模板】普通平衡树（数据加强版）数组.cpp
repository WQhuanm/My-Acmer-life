#include <bits/stdc++.h>
using namespace std;
#define inf (1<<30)
#define endl             "\n"
const int N = 2e6 + 10;

struct AVL
{
	struct avlnode
	{
		int l, r;
		int val, dep, cnt, sz;
	} t[N];
	int cnt = 0, root = 0;
	
	void init()
	{
		for (int i = 0; i <= cnt; ++i)t[i].l = t[i].r = 0;
		cnt = 0;
	}
	inline void newnode(int &p, int val)
	{
		t[p = ++cnt] = {0, 0, val, 1, 1, 1};
	}
	
	inline void update(int p)
	{
		if (!p)return;
		t[p].dep = max(t[t[p].l].dep, t[t[p].r].dep) + 1;
		t[p].sz = t[t[p].l].sz + t[t[p].r].sz + t[p].cnt;
	}
//右儿子多，左旋
	inline void lx(int &p)
	{
		int q = t[p].r;
		t[p].r = t[q].l, t[q].l = p;
		update(p), update(q);
		p = q;
	}
//右旋
	inline void rx(int &p)
	{
		int q = t[p].l;
		t[p].l = t[q].r, t[q].r = p;
		update(p), update(q);
		p = q;
	}
//平衡因子
	inline int BF(int p)
	{
		return t[t[p].l].dep - t[t[p].r].dep;
	}
//检查平衡
	inline void check(int&p)
	{
		if (!p)return;
		int bf = BF(p);
		if (bf > 1)//L型，需要右旋
		{
			int lf = BF(t[p].l);
			if (lf >= 0)rx(p);//LL
			else lx(t[p].l), rx(p); //LR
		}
		else if (bf < -1)//左旋
		{
			int rf = BF(t[p].r);
			if (rf <= 0)lx(p);
			else rx(t[p].r), lx(p);
		}
		update(p);
	}
//插入
	void _insert(int&p, int val)
	{
		if (!p)return newnode(p, val), void();
		else if (t[p].val == val) t[p].cnt++;//不能return,后后面要update更新
		else if (val < t[p].val)_insert(t[p].l, val);
		else _insert(t[p].r, val);
		update(p), check(p);
	}
//查找
	bool _find(int p, int val)
	{
		if (!p)return 0;
		else if ( t[p].val == val)return 1;
		else if (val < t[p].val)return _find(t[p].l, val);
		else return _find(t[p].r, val);
	}
//遍历(小到大)
	void inorder(int p)
	{
		if (!p)return;
		inorder(t[p].l);
		cout << t[p].val << endl;
		inorder(t[p].r);
	}
//前驱
	int pre(int x)
	{
		int ans = -inf;//ans初始为极小
		int p = root;
		while (p)
		{
			if (t[p].val == x)
			{
				if (t[p].l)
				{
					p = t[p].l;
					while (t[p].r)p = t[p].r;
					ans = t[p].val;
				}
				break;
			}
			if (t[p].val < x && t[p].val > ans)ans = t[p].val;
			p = (t[p].val < x ? t[p].r : t[p].l);
		}
		return ans;
	}
//后继
	int nxt(int x)
	{
		int ans = inf;//ans初始化极大
		int p = root;
		while (p)
		{
			if (t[p].val == x)
			{
				if (t[p].r)
				{
					p = t[p].r;
					while (t[p].l)p = t[p].l;
					ans = t[p].val;
				}
				break;
			}
			if (t[p].val > x && t[p].val < ans)ans = t[p].val;
			p = (t[p].val < x ? t[p].r : t[p].l);
		}
		return ans;
	}
//删除
	void del(int& p, int val)
	{
		if (!p)return;
		if (t[p].val > val)del(t[p].l, val);
		else if (t[p].val < val)del(t[p].r, val);
		else
		{
			if (t[p].cnt > 1)t[p].cnt--;
			else if (t[p].l && t[p].r)
			{
				int  q = t[p].l;
				while (t[q].r)q = t[q].r; //找左儿子最大的
				t[p].cnt = t[q].cnt, t[p].val = t[q].val, t[q].cnt = 1;
				del(t[p].l, t[q].val);
			}
			else
			{
				if (t[p].l)p = t[p].l;
				else if (t[p].r)p = t[p].r;
				else p = 0;
			}
		}
		update(p), check(p);
	}
//查询val排第几
	int get_rate(int p, int val)
	{
		if (!p)return 1;//所有元素都比val小啦
		if (t[p].val > val)return get_rate(t[p].l, val);
		else if (t[p].val == val)return t[t[p].l].sz + 1;
		else return t[t[p].l].sz + t[p].cnt + get_rate(t[p].r, val);
	}
//查询第k小
	int get_k(int p, int k)
	{
		if (!p)return 0;
		if (t[t[p].l].sz >= k)return get_k(t[p].l, k);
		else if (t[t[p].l].sz + t[p].cnt >= k)return t[p].val;
		else return get_k(t[p].r, k - t[t[p].l].sz - t[p].cnt);
	}
} a;

int n, m;

void mysolve()
{
	int  op, x, ans = 0, sum = 0;
	cin >> n >> m;
	while (n--)cin >> x, a._insert(a.root, x);
	while (m--)
	{
		cin >> op >> x;
		x ^= ans;
		if (op == 1)a._insert(a.root, x);
		else if (op == 2)a.del(a.root, x);
		else if (op == 3)ans = a.get_rate(a.root, x), sum ^= ans;
		else if (op == 4)ans = a.get_k(a.root, x), sum ^= ans;
		else if (op == 5)ans = a.pre(x), sum ^= ans;
		else ans = a.nxt(x), sum ^= ans;
	}
	cout << sum << endl;
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);//使用read请把解绑注释了
	mysolve();
	system("pause");
	return 0;
}
