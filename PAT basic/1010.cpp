#include<iostream>
using namespace std;

int main()
{
    int times = 0;
    int c, p;
    while(cin >> c >> p)
    {
        if(p == 0)
        {
            if(times == 0)
            {
                cout << 0 << " " << 0;
            }
        }
        else
        {
            c = c * p;
            p--;
            if(times != 0)
                cout << " ";
            cout << c << " " << p;
        }
        times++;
    }
//     cout << endl;
    return 0;
}
