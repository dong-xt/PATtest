#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 1] = {0};
    for(int i = 0; i < n; i++)
    {
        int dis;
        cin >> dis;
        if(dis > n)
            a[n]++;
        else if(dis == 0)
            a[0]++;
        else
            a[dis - 1]++;
    }
    for(int i = n; i >= 0; i--)
    {
        if(a[i] >= i)
        {
            cout << i;
            break;
        }
        else
            a[i-1] += a[i];
    }
    
    return 0;
}
