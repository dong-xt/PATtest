#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> s >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int cnt = 0;
        string _s = "";        
        for(int j = 0; j < s.length(); j++)
        {
            if(j + 1 >= s.length() || s[j + 1] != s[j])
            {
                cnt++;
                _s += s[j];
                _s += to_string(cnt);
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        s = _s; 
    }
    cout << s << endl;
    return 0;
}
