#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore(10, '\n');
    for(int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        bool wrongchar = false, wrongnum = true, wrongeng = true;
        if(s.length() < 6)
        {
            cout << "Your password is tai duan le." << endl;
        }
        else
        {
            for(int i = 0; i < s.length(); i++)
            {
                if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                {
                    wrongeng = false;
                }
                else if(s[i] >= '0' && s[i] <= '9')
                {
                    wrongnum = false;
                }
                else if(s[i] != '.')
                {
                    wrongchar = true;
                }
            }
            if(wrongchar) cout << "Your password is tai luan le." << endl;
            else if(wrongnum) cout << "Your password needs shu zi." << endl;
            else if(wrongeng) cout << "Your password needs zi mu." << endl;
            else cout << "Your password is wan mei." << endl;
        }
    }
    return 0;
}
