#include <bits/stdc++.h>
using namespace std;
#define ll               long long
typedef pair<int, int> pii;
#define inf (1<<30)
#define endl             "\n"

struct AVL
{
	struct avlnode;
	typedef avlnode* avl;
	struct avlnode
	{
		avl l, r;
		int val, dep, cnt, sz;
		avlnode(): l(NULL), r(NULL), val(0), dep(1), cnt(1), sz(1) {}
		avlnode(int a): l(NULL), r(NULL), val(a), dep(1), cnt(1), sz(1) {}
	};
	avl root;

	inline int get_sz(avl p)
	{
		if (p == NULL)return 0;
		return p->sz;
	}

	inline int get_dep(avl p)
	{
		if (p == NULL)return 0;
		return p->dep;
	}

	inline void update(avl &p)
	{
		if (p == NULL)return;
		p->dep = max(get_dep(p->l), get_dep(p->r)) + 1;
		p->sz = get_sz(p->l) + get_sz(p->r) + p->cnt;
	}
//右儿子多，左旋
	inline void lx(avl &p)
	{
		avl q = p->r;
		p->r = q->l;
		q->l = p;
		update(p), update(q);
		p = q;
	}
//右旋
	inline void rx(avl&p)
	{
		avl q = p->l;
		p->l = q->r;
		q->r = p;
		update(p), update(q);
		p = q;
	}
//平衡因子
	inline int BF(avl p)
	{
		return get_dep(p->l) - get_dep(p->r);
	}
//检查平衡
	inline void check(avl&p)
	{
		if (p == NULL)return;
		int bf = BF(p);
		if (bf > 1)//L型，需要右旋
			{
				int lf = BF(p->l);
				if (lf >= 0)rx(p);//LL
				else lx(p->l), rx(p); //LR
			}
		else if (bf < -1)//左旋
			{
				int rf = BF(p->r);
				if (rf <= 0)lx(p);
				else rx(p->r), lx(p);
			}
		update(p);
	}
//插入
	void _insert(avl &p, int val)
	{
		if (p == NULL)return p = new avlnode(val), void();
		else if (p->val == val) p->cnt++;//不能return,后后面要update更新
		else if (val < p->val)_insert(p->l, val);
		else _insert(p->r, val);
		update(p), check(p);
	}
//查找
	bool _find(avl p, int val)
	{
		if (p == NULL)return 0;
		else if ( p->val == val)return 1;
		else if (val < p->val)return _find(p->l, val);
		else return _find(p->r, val);
	}
//遍历(小到大)
	void inorder(avl p)
	{
		if (p == NULL)return;
		inorder(p->l);
		cout << p->val << endl;
		inorder(p->r);
	}
//前驱
	int pre(int x)
	{
		int ans = -inf;//ans初始为极小
		avl p = root;
		while (p)
			{
				if (p->val == x)
					{
						if (p->l)
							{
								p = p->l;
								while (p -> r)p = p->r;
								ans = p->val;
							}
						break;
					}
				if (p->val < x && p->val > ans)ans = p->val;
				p = (p->val < x ? p->r : p->l);
			}
		return ans;
	}
//后继
	int nxt(int x)
	{
		int ans = inf;//ans初始化极大
		avl p = root;
		while (p)
			{
				if (p->val == x)
					{
						if (p->r)
							{
								p = p->r;
								while (p->l)p = p->l;
								ans = p->val;
							}
						break;
					}
				if (p->val > x && p->val < ans)ans = p->val;
				p = (p->val < x ? p ->r : p->l);
			}
		return ans;
	}
//删除
	void del(avl&p, int val)
	{
		if (p == NULL)return;
		if (p->val > val)del(p->l, val);
		else if (p->val < val)del(p->r, val);
		else
			{
				if (p->cnt > 1)p->cnt--;
				else if (p->l && p->r)
					{
						avl q = p->l;
						while (q->r)q = q->r; //找左儿子最大的
						p->cnt = q->cnt, p->val = q->val, q->cnt = 1;
						del(p->l, q->val);
					}
				else
					{
						avl q = p;
						if (p->l)p = p->l;
						else if (p->r)p = p->r;
						else p = NULL;
						delete q;//删除原来的p
					}
			}
		update(p), check(p);
	}
//查询val排第几
	int get_rate(avl p, int val)
	{
		if (p == NULL)return 1;//所有元素都比val小啦
		if (p->val > val)return get_rate(p->l, val);
		else if (p->val == val)return get_sz(p->l) + 1;
		else return get_sz(p->l) + p->cnt + get_rate(p->r, val);
	}
//查询第k小
	int get_k(avl&p, int k)
	{
		if (p == NULL)return inf;
		if (get_sz(p->l) >= k)return get_k(p->l, k);
		else if (get_sz(p->l) + p->cnt >= k)return p->val;
		else
			{
				int now = get_k(p->r, k - get_sz(p->l) - p->cnt);
				return (~now ? now : p->val);
			}
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
