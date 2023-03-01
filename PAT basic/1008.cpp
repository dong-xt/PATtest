#include <iostream>
using namespace std;

//另一种方法直接输出对应位置的数据
int main()
{
    int N, M;
    cin >> N >> M;
    int a[N];
    for(int i = 0; i < N; i++)
        cin >> a[i];
    for(int i = 0; i < M; i++)
    {
        int temp = a[0];
        for(int j = 0; j < N; j++)
        {
            if(j + 1 == N)
                a[0] = temp;
            else
            {
                int temp2 = a[j + 1];
                a[j + 1] = temp;
                temp = temp2;
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        cout << a[i];
        if(i != N - 1)
            cout << " ";
        else
            cout << endl;
    }
   
    return 0;
}
