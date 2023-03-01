#include<iostream>
using namespace std;

int main()
{
    int m, x, y;
    cin >> m >> x >> y;
    bool find = false;
    int jia = 0, yi = 0;
    double bing = 0.0;//丙未必为整数
    for(int i = 9; i >= 1; i--)
    {
        for(int j = 9; j >= 0; j--) //个位可以取0
        {
            jia = 10 * i + j;
            yi = 10 * j + i;
            int error = abs(jia - yi);
            if((double)error / x == (double)yi / y)
            {
                bing = (double)error / x;
                find = true;
                break;
            }
        }
        if(find) break;
    }
    if(!find)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        cout << jia << " ";
        if(jia > m) cout << "Cong" << " ";
        else if(jia < m) cout << "Gai" << " ";
        else cout << "Ping" << " ";            
        if(yi > m) cout << "Cong" << " ";
        else if(yi < m) cout << "Gai" << " ";
        else cout << "Ping" << " ";
        if(bing > m) cout << "Cong" << endl;
        else if(bing < m) cout << "Gai" << endl;
        else cout << "Ping" << endl;         
    }
    return 0;
}
