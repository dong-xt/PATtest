#include<iostream>
#include<string>
using namespace std;

int main()
{
    string n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.length() < n.length()) s1 = string(n.length() - s1.length(), '0') + s1;
    if(s2.length() < n.length()) s2 = string(n.length() - s2.length(), '0') + s2;
    int advance = 0;
    string ss = "";
    for(int i = n.length() - 1; i >= 0; i--)
    {
        int sum = s1[i] + s2[i] - 2 * '0' + advance;
        int ntype = (int)(n[i] - '0');
        if(ntype == 0) ntype = 10;
        advance = sum / ntype;
        ss = (char)(sum % ntype + '0') + ss;
    }
    while(advance != 0)
    {
        ss = (char)(advance % 10 + '0') + ss;
        advance /= 10;
    }
    for(int i = 0; i < ss.length(); i++)
    {
        if(ss[i] != '0')
        {
            cout << ss.substr(i, ss.length() - i) << endl;
            break;
        }
        else if(i == ss.length() - 1 && ss[i] == '0')
            cout << "0" << endl;
    }
    
    return 0;
}
