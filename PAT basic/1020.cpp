#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

struct GOODS{
   float num;   //库存和总售价不一定是整数
   float allprice;
   float price;
};

bool cmp(GOODS g1, GOODS g2)
{
    return g1.price > g2.price;
}

int main()	
{
    int n, d;
    cin >> n >> d;
    GOODS g[n];
    for(int i = 0; i < n; i++)
        cin >> g[i].num;        
    for(int i = 0; i < n; i++)
    {
        cin >> g[i].allprice;
        g[i].price = g[i].allprice / g[i].num;
    }
    sort(g, g + n, cmp);
    int sold = 0; int i = 0; float value = 0.0;
    while(sold < d && i < n)
    {
        if(g[i].num + sold >= d)
        {
        	value += (d - sold) / g[i].num * g[i].allprice;
            sold = d;
        }
        else 
        {
            sold += g[i].num;
            value += (float)g[i].allprice;
            i++;
        }
    }
    printf("%.2f\n", value);
    
    return 0;
}
