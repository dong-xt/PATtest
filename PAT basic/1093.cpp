#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    string c = "";
    while(a.length() != 0)
    {
        char add = a[0];
        c += add;
        a.erase(remove(a.begin(), a.end(), add), a.end());
        b.erase(remove(b.begin(), b.end(), add), b.end());
    }
    while(b.length() != 0)
    {
        char add = b[0];
        c += add;
        b.erase(remove(b.begin(), b.end(), add), b.end());
    }
    cout << c << endl;
    return 0;
}
