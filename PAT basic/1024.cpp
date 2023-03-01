#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s;
	cin >> s;
	char dir = s[0];
	char front = s[1];
// 	cout << "front " << front << endl; 
	int i = 3;
	while(s[i] != 'E')
	{
		i++;
	}
// 	cout << "i " << i << endl;
	char powdir = s[i + 1];
// 	cout << "powdir " << powdir << endl;
	string _dis = s.substr(i + 2, s.length() - i - 2); 
// 	cout << "_dis " << _dis << endl;
	int dis = stoi(_dis);
// 	cout << "dis " << dis << endl;
	dis = (powdir == '+') ? dis : (-1 * dis);
	dis -= (i-3);
// 	cout << "dis " << dis << endl;
    string back = s.substr(3, i - 3);
//     cout << "back " << back << endl;
	string _s = front + back;
// 	cout << "_s " << _s << endl;
	if(dis > 0)
	{
		if(dir == '-') cout << dir;
		cout << _s << string(dis, '0') << endl;
	}
	else if(dis < 0)
	{
		if(-1 * dis < _s.length())
		{
			_s.insert(_s.length() + dis, ".");
			if(dir == '-') cout << dir;
			cout << _s << endl;
		}
		else
		{
			dis += _s.length();
			_s = "0." + string(-1 * dis, '0') + _s;
			if(dir == '-') cout << dir;
			cout << _s << endl;
		}
	}
	else if(dis == 0)
	{
		if(dir == '-') cout << dir;
		cout << _s << endl;
	}
    return 0;
}
