#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int sellmax = -1, summax = -1;
    string sellmaxname, summaxname;
    for(int i = 0; i < n; i++)
    {
        string name;
        int price, sell;
        cin >> name >> price >> sell;
        if(sell > sellmax)
        {
            sellmax = sell;
            sellmaxname = name;
        }
        if(price * sell > summax)
        {
            summax = price * sell;
            summaxname = name;
        }
    }
    cout << sellmaxname << " " << sellmax << endl;
    cout << summaxname << " " << summax << endl;
    return 0;
}
