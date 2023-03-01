#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	char tag;
	cin >> n >> tag;
	int init = 0;
	int left = 0;
	for(int i = 1; i < 23; i++)
	{
		int h = (i + 1) * (i + 1) * 2 - 1;
		int l = i * i * 2 - 1;
		if(n >= l && n < h)
		{
			init = i;
			left = n - l;
		}
	}
	for(int i = init; i >= 1; i--)
	{
		string s = string(2 * i - 1, tag);
		string blank = string(init - i, ' ');
		cout << blank << s << endl;
	} 
	for(int i = 2; i <= init; i++)
	{
		string s = string(2 * i - 1, tag);
		string blank = string(init - i, ' ');
		cout << blank << s << endl;
	}
	cout << left << endl;
    return 0;
}
