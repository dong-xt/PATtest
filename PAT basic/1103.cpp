#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    bool find = false;
    for(int a = m; a <= n; a++)
    {
        long long a3 = pow(a, 3) - pow(a - 1, 3);
        long long c = sqrt(a3);
        if(c * c == a3)
        {
            for(int b = 2; b < c; b++)
            {
                long long b2 = pow(b, 2) + pow(b - 1, 2);
                if(c == b2)
                {
                    find = true;
                    cout << a << " " << b << endl;
                }
            }            
        }

    }
    if(!find) cout << "No Solution" << endl;
    return 0;
}
