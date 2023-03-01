#include<iostream>
#include<map>
#include<cmath>
#include<iomanip>
#include<stdio.h>
using namespace std;

int main()
{
    int a, b;
    int n, m;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &n, &m);
    int ans[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &ans[i][j]);
    bool stay[n];   //记录每个人是否出局
    fill(stay, stay + n, true);
    int num[n * m];     //记录提出的有效数
    bool nummap[100000] = {false};     //记录所有出现过的数
    int errmap[100000] = {0};       //记录所有出现的差值
    //最初a b以及形成的差值
    num[0] = a; num[1] = b; nummap[a-1] = true; nummap[b-1] = true; errmap[abs(a - b)] = 1; 
    int cnt = 2;
    int alive = n;  //还活着的人
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(stay[i]) //该玩家是否没出局
            {   //差值可用 并且 这个数没出现过
                if(errmap[ans[i][j]] == 1 && !nummap[ans[i][j] - 1])
                {
                    nummap[ans[i][j] - 1] = true;
                    errmap[ans[i][j]] = 2;
                    for(int k = 0; k < cnt; k++)    //和新有效数形成新的差值
                    {
                        int err = abs(num[k] - ans[i][j]);
                        if(!nummap[err-1])
                            errmap[err] = 1;
                    }
                    num[cnt] = ans[i][j];
                    cnt++;
                }
                else
                {
                    stay[i] = false;
                    printf("Round #%d: %d is out.\n", j + 1, i + 1);
                    alive--;
                    if(alive == 0) break;
                    continue;
                }
            }
            else continue;
        }
        if(alive == 0) break;
    }
    if(alive == 0)
        printf("No winner.");
    else
    {
        printf("Winner(s):");
        for(int i = 0; i < n; i++)
        {
            if(stay[i])
            {
                printf(" %d", i+1);
            }
        }
    }
    printf("\n");
    return 0;
}
