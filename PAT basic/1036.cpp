#include<iostream>
using namespace std;

int main()
{
    int n;
    char c;
    cin >> n >> c;
    int vl = (int)((float)n / 2 + 0.5);
    for(int i = 0; i < vl; i++)
    {
        if(i == 0 || i == vl - 1)
        {
            for(int j = 0; j < n; j++) cout << c;
            cout << endl;
        }
        else
        {
            cout << c;
            for(int j = 1; j < n - 1; j++) cout << " ";
            cout << c << endl;            
        }
    }
    return 0;
}
