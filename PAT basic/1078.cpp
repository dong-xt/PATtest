#include<iostream>
#include<string>
using namespace std;

int main()
{
    char c;
    cin >> c;
    cin.ignore(10, '\n');
    string s;
    getline(cin, s);    
    if(c == 'C')
    {
        int cnt = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(i == s.length() - 1)
            {
                if(s[i] == s[i-1])
                {
                    cnt++; 
					cout << cnt << s[i];
                    cnt = 0;
                }
                else
                {
                    cout << s[i];
                }
            }
            else if(s[i] == s[i + 1])
            {
                cnt++;
            }
            else if(s[i] != s[i + 1])
            {
                cnt++;
                if(cnt > 1) cout << cnt << s[i];
                else cout << s[i];
                cnt = 0;
            }
        }
        cout << endl;
    }
    else if(c == 'D')
    {
        bool find = false;
        int pos = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] >= '0' && s[i] <= '9' && !find)
            {
                find = true;
                pos = i;
            }
            else if((s[i] < '0' || s[i] > '9') && find)
            {
                string _num = s.substr(pos, i - pos);
                int num = stoi(_num);
                for(int j = 0; j < num; j++)
                {
                    cout << s[i];
                }
                find = false;
                pos = 0;
            }
            else if(!find && (s[i] < '0' || s[i] > '9'))
            {
                cout << s[i];
            }
        }
        cout << endl;
    }
    return 0;
}
