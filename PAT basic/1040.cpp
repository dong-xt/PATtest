#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long cnt_t = 0, cnt_at = 0, cnt_pat = 0;
    for(int i = s.length() - 1; i >= 0; i--)
    {
        if(s[i] == 'T')
        {
            cnt_t++;
        }
        else if(s[i] == 'A')
        {
            cnt_at += cnt_t;
        }
        else if(s[i] == 'P')
        {
            cnt_pat += cnt_at;
            if(cnt_pat >= 1000000007)
                cnt_pat %= 1000000007;
        }
    }
    cout << cnt_pat << endl;
    return 0;
}
