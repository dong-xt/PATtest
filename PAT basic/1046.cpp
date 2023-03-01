#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int as, ag, bs, bg;
    int ad = 0, bd = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> as >> ag >> bs >> bg;
        if(as + bs == ag && as + bs != bg)
        {
            bd++;
        }
        else if(as + bs != ag && as + bs == bg)
        {
            ad++;
        }
    }
    cout << ad << " " << bd << endl;
    return 0;
}
