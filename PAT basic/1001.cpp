#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int step = 0;
	while(n != 1)
	{
		if(n % 2 == 0)
			n /= 2;
		else
			n = (3*n+1)/2;
		step ++;
	}   
	cout << step;
	
	return 0;
}
