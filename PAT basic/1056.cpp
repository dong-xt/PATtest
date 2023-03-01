#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num[n];
    for(int i = 0; i < n; i++)
        cin >> num[i];
    int sum = 0;
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j <= n-1; j++)
        {
            sum += num[i] * 10 + num[j];
            sum += num[j] * 10 + num[i];
        }
    }
    cout << sum << endl;
    return 0;
}
