#include <bits/stdc++.h>
using namespace std;
#define ll               long long
#define endl             "\n"
#define int              long long

bool judnum(char c)//0是字母数字
{
	if ((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9'))return 0;
	else return 1;
}
bool judb(char c)//符号返回1
{
	if (judnum(c)==0||c==' ')return 0;
	else return 1;
}

void mysolve()
{
	int n;
	cin>>n;
	getchar();
	while (n--)
		{
			string s;
			getline(cin,s);
			cout<<s<<endl;
			cout<<"AI: ";
			for (int i=0; i<(int)s.size(); ++i)//先全部转为小写
				{
					if (s[i]>='A'&&s[i]<='Z'&&s[i]!='I')s[i]=s[i]-'A'+'a';
				}
			string a="";
			bool fl=1;
			while (fl)
				{
					bool flag=1;
					a="";
					fl=0;
					int tk=0;
					int len=(int)s.size();
					for (int i=0; i<len; ++i)
						{
							if (flag&&s[i]==' ')continue;//删除前导空格
							else
								{
									if (s[i]==' ')
										{
											if (i+1<len&&judb(s[i+1]))continue;//空格后面是符号
											else if (tk>0)//多个空格
												{
													fl=1;//删除多个空格，需要重来一次
													continue;
												}
											else if (tk==0)
												{
													tk=1;
													a+=' ';
													continue;
												}
										}
									else//不是空格
										{
											tk=0;
											flag=0;
											if (s[i]=='?')
												{
													a+='!';
													continue;
												}
											if (s[i]=='I'&&judnum(s[i-1])&&judnum(s[i+1])&&!(s.substr(i,5)=="I Can"&&judnum(s[i+5]))&&!(s.substr(i,7)=="I Could"&&judnum(s[i+7])))
												{
													a+="You";//大写防止被转化
													continue;
												}
											if (s[i]=='m'&&s[i+1]=='e'&&judnum(s[i-1])&&judnum(s[i+2]))
												{
													i++;
													a+="You";
													continue;
												}
											if (s[i]=='c')
												{
													string tmp=s.substr(i,min((int)s.size()-i+1,7ll));
													if (tmp=="can you"&&judnum(s[i+7])&&(i==0||judnum(s[i-1])))
														{

															a+="I Can";
															i+=6;
															continue;
														}
													tmp=s.substr(i,min((int)s.size()-i+1,9ll));
													if (tmp=="could you"&&judnum(s[i+9])&&(i==0||judnum(s[i-1])))
														{

															a+="I Could";
															i+=8;
															continue;
														}
												}
										}

									a+=s[i];
								}
						}
					while ((int)a.size()&& *a.rbegin()==' ')a.pop_back();//删除后导空格
					s=a;
				}
			for (int i=0; i<(int)a.size(); ++i)
				{
					if (a[i]>='A'&&a[i]<='Z'&&a[i]!='I')a[i]=a[i]-'A'+'a';//因为转化保留一些大写字母，改写回来
				}
			cout<<a<<endl;

		}

}

int32_t main()
{
	//std::ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	mysolve();

	system("pause");
	return 0;
}
