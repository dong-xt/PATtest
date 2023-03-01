#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main()
{
    int m, n, a, b, v;
    scanf("%d%d%d%d%d", &m, &n, &a, &b, &v);    //修改为scanf才不超时
    int in;
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d",&in);
            if(in >= a &&in <= b)
                in = v;
//             printf("%03d", in);
            cout << setw(3) << setfill('0') << in;
            if(j != n-1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
