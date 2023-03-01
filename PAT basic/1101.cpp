#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
    string a;
    int d;
    cin >> a >> d;
    string b = a.substr(a.length()-d, d) + a.substr(0, a.length()-d);
    long long _a = stoll(a);
    long long _b = stoll(b);
    printf("%.2f\n", (double)_b/_a);
    return 0;
}
