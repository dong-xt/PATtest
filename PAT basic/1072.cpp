#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    bool forbid[10000];
    fill(forbid, forbid + 10000, false);
    for(int i = 0; i < m; i++)
    {
        int idx;
        cin >> idx;
        forbid[idx] = true;
    }
    int cnt_stu = 0, cnt_stf = 0;
    for(int i = 0; i < n; i++)
    {
        string name;
        int k;
        cin >> name >> k;
        bool capture = false;
        for(int j = 0; j < k; j++)
        {
            int checkidx;
            cin >> checkidx;
            if(forbid[checkidx])
            {
                if(!capture)
                {
                    capture = true;
                    cnt_stu++;
                    cout << name << ":";
                }
                cnt_stf++;
                cout << " " << setw(4) << setfill('0') << checkidx;
            }
        }
        if(capture) cout << endl;
    }
    cout << cnt_stu << " " << cnt_stf << endl;
    return 0;
}
