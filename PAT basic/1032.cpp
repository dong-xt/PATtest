#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int grade[n] = {0};
	int max = 0;
	int max_id = 0; 
	for(int i = 0; i < n; i++)
	{
		int id, score;
		cin >> id >> score;
		grade[id - 1] += score;
		if(grade[id - 1] >= max)
		{
			max_id = id;
			max = grade[id - 1];
		}
	}
	cout << max_id << " " << max << endl;
    return 0;
}
