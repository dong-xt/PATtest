#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main()
{
	unsigned int c1, c2;
	cin >> c1 >> c2;
	unsigned int c_error = c2 - c1;
	float _second = (float)c_error / 100;
	unsigned int second = (unsigned int)(_second + 0.5);
	unsigned hh, mm, ss;
	hh = second / 3600;
	second %= 3600;
	mm = second / 60;
	second %= 60;
	ss = second;
	printf("%02u:%02u:%02u", hh, mm, ss);
	
    return 0;
}
