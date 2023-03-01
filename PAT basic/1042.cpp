#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int cnt[26] = {0};
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            cnt[s[i] - 'a']++;
        else if(s[i] >= 'A' && s[i] <= 'Z')
            cnt[s[i] - 'A']++;
    }
    int index = 0;
    int num = cnt[0];
    for(int i = 1; i < 26; i++)
    {
        if(cnt[i] > num)
        {
            index = i;
            num = cnt[i];
        }
    }
    cout << (char)('a' + index) << " " << num << endl;
    return 0;
}
