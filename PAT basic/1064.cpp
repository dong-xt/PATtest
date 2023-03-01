#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int num[n];
    int cnt = 0;
    bool record[40];
    fill(record, record + 40, false);
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int sum = 0;
        for(int j = 0; j < s.length(); j++)
            sum = sum + (s[j] - '0');
        if(!record[sum])
        {
            num[cnt] = sum;
            cnt++;
            record[sum] = true;
        }
    }
    sort(num, num + cnt);
    cout << cnt << endl;
    for(int i = 0; i < cnt; i++)
    {
        cout << num[i];
        if(i == cnt - 1) cout << endl;
        else cout << " ";
    }
    return 0;
}
