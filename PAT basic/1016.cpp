#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int reunite(string s, char d)
{
    int l = s.length();
    int cnt = 0;
    for(int i = 0; i < l; i++)
    {
        if(s[i] == d)
            cnt++;
    }
    int _d = d - '0';
    int newnum = 0;
    for(int i = 0; i < cnt; i++)
    {
        newnum += _d * pow(10, i);
    }
    return newnum;
}

int main()
{
    string s1, s2;
    char da, db;
    cin >> s1 >> da >> s2 >> db;
    cout << reunite(s1, da) + reunite(s2, db) << endl;
    
    return 0;
}

