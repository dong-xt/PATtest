#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            string s;
            cin >> s;
            if(s[2] == 'T')
            {
                cout << (int)(s[0] - 'A' + 1);
            }
        }
    }
    cout << endl;
    return 0;
}
