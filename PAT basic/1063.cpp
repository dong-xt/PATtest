#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int max = 0;
    double r = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        int pow = a * a + b * b;
        if(pow >= max)
        {
            max = pow;
            r = sqrt((double)pow);
        }
    }
    printf("%.2f\n", r);
    return 0;
}
