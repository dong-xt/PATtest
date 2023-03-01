#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string s = "";
    int length = 0;
    for(int i = 0; i < 10; i++)
    {
        int cnt;
        cin >> cnt;
        if(cnt != 0)
            for(int j = 0; j < cnt; j++)
            {
                s += (char)(i + '0');
                length++;
            }
    }
    sort(s.begin(), s.end());
    if(s[0] == '0')
    {
        for(int i = 1; i < length; i++)
        {
            if(s[i] != '0')
            {
                s[0] = s[i];
                s[i] = '0';
                break;
            }
        }        
    }
    cout << s << endl;
    return 0;
}
