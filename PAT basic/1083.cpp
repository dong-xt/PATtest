#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int c[n];
    fill(c, c+n, 0);
    for(int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        int err = abs(i + 1 - in);
        c[err]++;
    }
    for(int i = n-1; i >= 0; i--)
    {
        if(c[i] >= 2)
        {
            cout << i << " " << c[i] << endl;
        }
    }
    return 0;
}
