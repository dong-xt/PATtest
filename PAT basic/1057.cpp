#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int sum = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z') sum += (s[i] - 'a' + 1);
        else if(s[i] >= 'A' && s[i] <= 'Z') sum += (s[i] - 'A' + 1);
    }
    int cnt0 = 0, cnt1 = 0;
    while(sum != 0)
    {
        (sum % 2 == 0) ? cnt0++ : cnt1++;
        sum /= 2;
    }
    cout << cnt0 << " " << cnt1 << endl;
    return 0;
}
