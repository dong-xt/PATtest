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
    bool stay[n];   //��¼ÿ�����Ƿ����
    fill(stay, stay + n, true);
    int num[n * m];     //��¼�������Ч��
    bool nummap[100000] = {false};     //��¼���г��ֹ�����
    int errmap[100000] = {0};       //��¼���г��ֵĲ�ֵ
    //���a b�Լ��γɵĲ�ֵ
    num[0] = a; num[1] = b; nummap[a-1] = true; nummap[b-1] = true; errmap[abs(a - b)] = 1; 
    int cnt = 2;
    int alive = n;  //�����ŵ���
    for(int j = 0; j < m; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(stay[i]) //������Ƿ�û����
            {   //��ֵ���� ���� �����û���ֹ�
                if(errmap[ans[i][j]] == 1 && !nummap[ans[i][j] - 1])
                {
                    nummap[ans[i][j] - 1] = true;
                    errmap[ans[i][j]] = 2;
                    for(int k = 0; k < cnt; k++)    //������Ч���γ��µĲ�ֵ
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
