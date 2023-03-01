#include<iostream>
#include<string>
using namespace std;

int main()
{
    int n, d;
    double e;
    cin >> n >> e >> d;
    int empty = 0, likeempty = 0;
    for(int i = 0; i < n; i++)
    {
        int day, lowcnt = 0;
        double ek;
        cin >> day;
        for(int j = 0; j < day; j++)
        {
            cin >> ek;
            if(ek < e) lowcnt++;
        }
    	if(lowcnt > day / 2)
        {
            (day > d) ? empty++ : likeempty++;
        }
    }
    double pa = (double)empty / n * 100.0;
    double pb = (double)likeempty / n * 100.0;
    printf("%.1f", pb);
    cout << "% ";
    printf("%.1f", pa);
    cout << "%" << endl;
    return 0;
}
