#include<iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    int begin = -1, end = -1;
    int max = 0;
    bool find = false;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if(num > t)
        {
            find = true;
            if(begin >= 0) end = i;
            else{
                begin = i;
                end = i;
            }
            if(i == n-1)
                cout << "[" << begin << ", " << end << "]" << endl;
        }
        else
        {
            if(begin >= 0 && end >= 0)
            {
                cout << "[" << begin << ", " << end << "]" << endl;
                begin = -1; end = -1;
            }
            if(num > max) max = num;
        }
    }
    if(!find) cout << max << endl;
    return 0;
}
