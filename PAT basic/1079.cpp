#include<iostream>
#include<string>
using namespace std;

bool ispalnum(string s)
{
    if(s == "0")
        return true;
    else
    {
        if(s[0] > '0')
        {
            int k = s.length() - 1;
            for(int i = 0; i < k / 2 + 1; i++)
            {
                if(s[i] != s[k - i])
                    return false;
            }
        }
        return true;
    }
}

string reverse(string s)
{
    string _s = "";
    for(int i = s.length() - 1; i >= 0; i--)
        _s += s[i];
    return _s;
}

string adds(string s, string _s)
{
    int div = 0;
    string ssum = "";
    for(int i = s.length() - 1; i >= 0; i--)
    {
        int sum = s[i] - '0' + _s[i] - '0' + div;
        div = sum / 10;
        sum %= 10;
        ssum = (char)(sum + '0') + ssum;
    }
    while(div > 0)
    {
        char head = div % 10 + '0';
        ssum = head + ssum;
        div /= 10;
    }
    return ssum;
}

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    while(!ispalnum(s))
    {
        if(cnt >= 10)
        {
            cout << "Not found in 10 iterations." << endl;
            return 0;
        }        
        string _s = reverse(s);
        string sum = adds(s, _s);
        cout << s << " + " << _s << " = " << sum << endl;
        cnt++;
        s = sum;
    }
    cout << s << " is a palindromic number." << endl;
    
    return 0;
}
