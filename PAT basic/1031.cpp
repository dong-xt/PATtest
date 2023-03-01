#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	const int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
	const char M[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	int n;
	cin >> n;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		int sum = 0;
		bool numcheck = true;
		for(int j = 0; j < 17; j++)
		{
			if(s[j] >= '0' && s[j] <= '9')
			{
				int num = s[j] - '0';
				sum += num * weight[j];
			}
			else
			{
				sum = 0;
				cout << s << endl;
				numcheck = false;
				break;
			}
		}
		if(numcheck)
		{
			sum %= 11;
			if(M[sum] != s[17])
			{
				cout << s << endl;
			}
			else
				cnt++;
		}
	}
	if(cnt == n)
		cout << "All passed" << endl;
    return 0;
}
