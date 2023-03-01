#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A1=0, A2=0, A3=0, A4=0, A5=0;
    int A2_dir = 1;
    int A2_cnt = 0;
    int A4_cnt = 0;
    for(int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if(a % 10 == 0)
            A1 += a;
        else if(a % 5 == 1)
        {
            A2 += A2_dir * a;
            A2_dir *= -1;
            A2_cnt++;
        }
        else if(a % 5 == 2)
            A3++;
        else if(a % 5 == 3)
        {
            A4 += a;
            A4_cnt++;
        }
        else if(a %5 == 4)
            if(a > A5)
                A5 = a;
    }
    cout << fixed << setprecision(1); //fixed 不用科学计数法
    (A1 == 0) ? (cout << "N ") : (cout << A1 << " ");
    (A2_cnt == 0) ? (cout << "N ") : (cout << A2 << " ");  //A2可能相加后为0 要用cnt判断
    (A3 == 0) ? (cout << "N ") : (cout << A3 << " ");
    (A4 == 0) ? (cout << "N ") : (cout << (float)A4 / A4_cnt << " "); //保证A4_cnt不为0 
    (A5 == 0) ? (cout << "N") : (cout << A5);

    return 0;
}
