#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	long p;
	cin >> N >> p;
	long a[N];
	for(int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N);
	int max_cnt = 0;
	for(int i = 0; i < N; i++)
	{
        if(i + max_cnt > N - 1)
            break;
		for(int j = i + max_cnt; j < N; j++)
		{
			if(a[i] * p >= a[j])
			{
				max_cnt = j - i + 1;
			}
			else
				break;
		}
	}
	cout << max_cnt << endl;
    return 0;
}
