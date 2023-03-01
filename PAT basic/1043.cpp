#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    unsigned int pos = 0;
    int cnt = 0, flag = 0;
    char a[6] = {'P', 'A', 'T', 'e', 's', 't'};
    while(cnt < 6)
    {
        if(s.find(a[flag]) != string::npos)
        {
            pos = s.find(a[flag]);
            cout << a[flag];
            s.erase(pos, 1);
            cnt = 0;
        }
        else
        {
            cnt++;            
        }
        flag = (flag == 5) ? 0 : flag + 1;
    }
    cout << endl;
    return 0;
}
