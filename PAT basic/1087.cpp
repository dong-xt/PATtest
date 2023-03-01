#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool res[2 * n];
    fill(res, res + 2 * n, false);
    int cnt = 0;
    for(int i = 1; i <= n; i++)
    {
        int cal = i / 2 + i / 3 + i / 5;
        if(!res[cal])
        {
            res[cal] = true;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
