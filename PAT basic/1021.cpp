#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int l = s.length();
    int cnt[10] = {0};
    for(int i = 0; i < l; i++)
        cnt[s[i] - '0']++;
    for(int i = 0; i < 10; i++)
        if(cnt[i] != 0)
            cout << i << ":" << cnt[i] << endl;
    return 0;
}
