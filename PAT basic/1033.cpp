#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main()
{
	string badkey, in;
	getline(cin, badkey);	//坏键有可能不存在
	cin >> in;
	if(badkey.empty())
		cout << in << endl;
	else
	{
		bool flag = false;
		int pos = 0; 
		if((pos = badkey.find("+")) != string::npos)
		{
			flag = true;
		}
		int l = in.length();
		for(int i = 0; i < l; i++)
		{
			char c = in[i];
			if(flag && c >= 'A' && c <= 'Z')
				continue;
			char _c = (c >= 'a' && c <= 'z') ? c - 'a' + 'A': c;
			if(badkey.find(_c) == string::npos)
				cout << c;
		}
		cout << endl;
	}
    return 0;
}
