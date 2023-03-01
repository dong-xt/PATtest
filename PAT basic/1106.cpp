#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s = "2019";
    for(int i = 0; i < n - 4; i++)
    {
        int sum = 0;
        for(int j = s.length() - 4; j < s.length(); j++)
        {
            sum += s[j] - '0';
        }
        sum %= 10;
        s += (char)(sum + '0');
    }
    cout << s.substr(0, n) << endl;
    return 0;
}
