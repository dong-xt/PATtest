#include<iostream>
using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    int dis = 1;
    int num[n][n];
    for(int i = 0; i < n; i++)
    {
        if((i + 1) % 2 == 1)
        {
            for(int k = 0; k < dis; k++)
            {
                num[i][k] = x;
            }
            for(int j = 0; j < n; j++)
            {
                int in; cin >> in;
                if(j < n - dis) num[i][j + dis] = in;
            }
            if(dis == k) dis = 1;
            else dis++;
        }
        else
        {
            for(int j = 0; j < n; j++)
            {
                int in;
                cin >> in;
                num[i][j] = in;
            }
        }
    }
    for(int j = 0; j < n; j++)
    {
        int sum = 0;
        for(int i = 0;i < n; i++)
        {
            sum += num[i][j];
        }
        if(j != 0) cout << " ";
        cout << sum;
    }
    cout << endl;

    return 0;
}
