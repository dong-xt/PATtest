#include <iostream>
#include <string>

using namespace std;

string get_g(int g)
{
    string _g = "";
    for(int i = 1; i <= g; i++)
    {
        _g += to_string(i);
    }
    return _g;
}

string get_bs(int bs, char type)
{
    string _bs = "";
    for(int i = 0; i < bs; i++)
    {
        _bs += type;
    }
    return _bs;
}

int main()
{
    int num;
    cin >> num;
    int g = num % 10;
    int s = (num / 10) % 10;
    int b = (num / 100) % 10;
    string _g, _s, _b;
    _g = (g == 0) ? (_g = "") : (get_g(g));
    _s = (s == 0) ? (_s = "") : (get_bs(s, 'S'));
    _b = (b == 0) ? (_b = "") : (get_bs(b, 'B'));
    
    cout << _b + _s + _g << endl;
    
    return 0;
}
