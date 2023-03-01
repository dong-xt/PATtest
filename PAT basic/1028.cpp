#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	string name, bd;
	const string today = "2014/09/06";
	const string limit = "1814/09/06";
	string old_day = today;
	string young_day = limit;
	string old, young;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> name >> bd;
		if(bd.compare(today) <= 0 && bd.compare(limit) >= 0)
		{
			cnt++;
			if(bd.compare(old_day) <= 0)
			{
				old_day = bd;
				old = name;
			}
			if(bd.compare(young_day) >= 0)
			{
				young_day = bd;
				young = name;				
			}
			//cout << cnt << " " << old << " " << young << endl;
		}
	}
    if(cnt != 0) //有可能不存在合法的数据
	    cout << cnt << " " << old << " " << young << endl;
    else
        cout << cnt << endl;
    return 0;
}
