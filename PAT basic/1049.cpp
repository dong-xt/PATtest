#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int n;
    cin >> n;
    long dis = n - 2;
    long weigh = n;
    long double sum = 0;    //精度问题 用long double或long float
    for(int i = 0; i < n; i++)
    {
        long double in;
        cin >> in;
        sum += in * weigh;
        weigh += dis;
        dis -= 2;
    }
    printf("%.2llf", sum);
    return 0;
}
