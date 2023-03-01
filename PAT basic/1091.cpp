#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int test;
        cin >> test;
        if(test == 0)
            cout << "0 0" << endl;
        else
        {
            bool find = false;
            for(int j = 1; j < 10; j++)
            {
                int nk = test * test * j;
                string _test = to_string(test);
                int l = _test.length();
                int div = pow(10, l);
                if(nk % div == test)
                {
                    find = true;
                    cout << j << " " << nk << endl;
                    break;
                }
            }
            if(!find) cout << "No" << endl;
        }
    }
    return 0;
}
