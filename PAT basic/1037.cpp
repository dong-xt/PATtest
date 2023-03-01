#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string sp, sa;
    cin >> sp >> sa;
    int pos = 0;
    string _s;
    int p[3], a[3], l[3];
    pos = sp.find("."); _s = sp.substr(0, pos); p[0] = stoi(_s); sp.erase(0, pos + 1);
    pos = sp.find("."); _s = sp.substr(0, pos); p[1] = stoi(_s); 
    _s = sp.substr(pos + 1, sp.length() - 1 - pos); p[2] = stoi(_s);
    pos = sa.find("."); _s = sa.substr(0, pos); a[0] = stoi(_s); sa.erase(0, pos + 1);
    pos = sa.find("."); _s = sa.substr(0, pos); a[1] = stoi(_s); 
    _s = sa.substr(pos + 1, sa.length() - 1 - pos); a[2] = stoi(_s);
    bool dir;
    if(p[0] * 17 * 29 + p[1] * 29 + p[2] <= a[0] * 17 * 29 + a[1] * 29 + a[2])
        dir = true;
    else
    {
        dir = false; 
        for(int i = 0; i < 3; i++)
        {
            int temp = a[i];
            a[i] = p[i];
            p[i] = temp;
        }
    }
    for(int i = 0; i < 3; i++)
        l[i] = a[i] - p[i];
    while(l[2] < 0)
    {
        l[2] += 29;
        l[1]--;
    }
    while(l[1] < 0)
    {
        l[1] += 17;
        l[0]--;
    }
    (dir) ? (cout << "") : (cout << "-");
    cout << to_string(l[0]) << "." << to_string(l[1]) << "." << to_string(l[2]) << endl;
    
    return 0;
}
