#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
	int N;
    cin >> N;
    int num[N];
    for(int i = 0; i < N; i++)
        cin >> num[i];
    sort(num, num + N);
    int m = 0, n = 0;
    for(int i = sqrt(N); i >= 1; i--) //有可能是一维数组
    {
        if(N % i == 0)
        {
            m = N / i;
            n = i;
            break;
        }
    }
    int r[m][n];
    memset(r, 0, sizeof(r)); 
    int idx = N - 1;
    int i = 0, j = -1;
    while(idx >= 0)
    {
        while(j + 1 <= n - 1 && r[i][j + 1] == 0)
            r[i][++j] = num[idx--];
        while(i + 1 <= m - 1 && r[i + 1][j] == 0)
            r[++i][j] = num[idx--];
        while(j - 1 >= 0 && r[i][j - 1] == 0)
            r[i][--j] = num[idx--];
        while(i - 1 >= 0 && r[i - 1][j] == 0)
            r[--i][j] = num[idx--];
    }
    for(i = 0; i < m; i++)
    {
        cout << r[i][0];
        for(j = 1; j < n; j++)
        {
            cout << " " << r[i][j];
        }
        cout << endl;
    }

    return 0;
}
