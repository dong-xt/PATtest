#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int upmin = 1001;
    for(int i = 0; i < n; i++)
    {
        int up;
        cin >> up;
        if(up < upmin) upmin = up;
    }
    int downmax = -1;
    for(int i = 0; i < n; i++)
    {
        int down;
        cin >> down;
        if(down > downmax) downmax = down;
    }
    int err = upmin - downmax;
    if(err >= 1) cout << "Yes " << err << endl;
    else cout << "No " << 1 - err << endl; 
    return 0;
}
