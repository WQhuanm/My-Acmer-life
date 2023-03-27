#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"

void mysolve()
{
	multiset<int>a,ans;
	string s;
	int n,x;
	cin>>n;
	while (n--)
		{
			cin>>s;
			if (s=="ADD")
				{
					cin>>x;
				//插入x前先判断原set有没有他前后的数
					auto it=a.lower_bound(x);
					if (it!=a.end())ans.insert(x^*it);
					if (it!=a.begin())ans.insert(x^*prev(it));
					if (it!=a.end()&&it!=a.begin())ans.erase(ans.find(*it^*prev(it)));
					a.insert(x);//最后插入
				}
			else if (s=="DEL")
				{
					cin>>x;
					a.erase(a.find(x));//删除是删除迭代器
				//删除后再判断set有没有其左右的数
					auto it=a.lower_bound(x);
					if (it!=a.end())ans.erase(ans.find(x^*it));
					if (it!=a.begin())ans.erase(ans.find(x^*prev(it)));
					if (it!=a.end()&&it!=a.begin())ans.insert(*it^*prev(it));
				}
			else
				{
					cout<<*ans.begin()<<endl;
				}
		}
}

int32_t main()
{
	std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	mysolve();
	system("pause");
	return 0;
}
