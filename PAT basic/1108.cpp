#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string gold = "String";
    int out = 0;
    int idx = 0;
    while(out != 6)
    {
        char c = gold[idx];
        if(s.find(c) != string::npos)
        {
            out = 0;
            int pos = s.find(c);
            s.erase(pos, 1);
            cout << c;
        }
        else
            out++;
        if(idx == 5) idx = 0;
        else idx++;
    }
    cout << endl;
    return 0;
}
