#include<iostream>
#include<climits>
using namespace std;

// short a = 1;
// int b = 2;
// long c = 3;
// long long d = 4;
// cout << sizeof(a) << endl;   2�ֽ�
// cout << sizeof(b) << endl;   4�ֽ�
// cout << sizeof(c) << endl;   8�ֽ�
// cout << sizeof(d) << endl;   8�ֽ�

int main()
{
    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        long A, B, C;
        cin >> A >> B >> C;
        if(A + B > C)
            cout << "Case #" << i + 1 << ": true" << endl;
        else
            cout << "Case #" << i + 1 << ": false" << endl;
    }
    return 0;
}
