#include <bits/stdc++.h>
using namespace std;
#define ll     long long
const int INF = 0x3f3f3f3f;
const int N = 2e5 + 100;

char b[1010];
string zic()
{
	char ch;
	string tmp = "", b = "";
	int n = 0;
	while (1)
		{
			ch = getchar();
			if (ch >= 'A' && ch <= 'Z')b += ch;
			else if (ch >= '0' && ch <= '9')n = n * 10 + (ch - '0');
			else if (ch == '[')
				{
					b += zic();
				}
			else if (ch == ']' || '\n')
				{
					if (!n)return b;
					else
						{
							tmp = b;
							for (int i = 2; i <= n; ++i)
								{
									b += tmp;
								}
							return b;
						}
				}

		}
	return b;
}

int main()
{
	cout << zic() << endl;
	return 0;
}
