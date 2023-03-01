#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main()
{
    int m, n, s;
    cin >> m >> n >> s;
    string award[m];
    fill(award, award + n, "");
    int cnt = 0, idx = s;
    for(int i = 0; i < m; i++)
    {
        string id;
        cin >> id;
        if(i + 1 == idx)
        {
            bool find = false;
            for(int j = 0; j < cnt; j++)
            {
                if(id == award[j])
                {
                    find = true;
                    break;
                }
            }
            if(!find)
            {
                cout << id << endl;
                award[cnt] = id;
                cnt++;
                idx += n;
            }
            else
            {
                idx++;
            }
        }
    }
    if(cnt == 0) cout << "Keep going..." << endl;
    return 0;
}
