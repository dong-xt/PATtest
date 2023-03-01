#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s;
    string _s = "";
    while(cin >> s)
    {
        _s = s + " " + _s;
    }
    cout << _s.substr(0, _s.length() - 1) << endl;

    return 0;
}

