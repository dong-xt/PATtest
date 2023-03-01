#include<iostream>
#include<string>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int c = a * b;
    string s = to_string(c);
    bool nonzero = false;
    for(int i = s.length() - 1; i >= 0; i--)
    {
        if(s[i] != '0' && !nonzero)
        {
            nonzero = true;
        }
        if(nonzero) cout << s[i];
    }
    cout << endl;
    return 0;
}
