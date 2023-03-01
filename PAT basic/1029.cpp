#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string s, _s;
	cin >> s >> _s;
	int i = 0, j = 0;
	int l = s.length();
	string bad = "";
	while(i < l)
	{
		char a = s[i];
		char b = _s[j];
		if(a != b)
		{
			if(a >= 'a' && a <= 'z')
				a = a - 'a' + 'A';
			if(bad.find(a) == string::npos)
			{
				bad += a;
			}
			i++;
		}
		else
		{
			i++;
			j++;
		}
	}
	cout << bad << endl; 
    return 0;
}
