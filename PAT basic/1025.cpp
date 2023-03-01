#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct Node
{
    int addr;
    int data;
    int next;
    int id = 0;
}list[100001];

bool cmp(Node n1, Node n2)
{
    return n1.id > n2.id;
}

int main()
{
    int head, n, k;
    cin >> head >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int addr;
        cin >> addr;
        list[addr].addr = addr;
        cin >> list[addr].data >> list[addr].next;
    }
    Node list1[n];
    int ptr = head, length = 0;
    while(ptr != -1)
    {
        list1[length] = list[ptr];
        list1[length].id = length;
        length++;
        ptr = list[ptr].next;
    }
    for(int i = 0;i < length; i += k)
    {
        if(i + k <= length)
        {
            sort(list1 + i, list1 + i + k, cmp);
        }
    }
    for(int i = 0; i < length; i++)
    {
        printf("%05d %d ", list1[i].addr, list1[i].data);        
        if(i == length - 1) printf("-1\n");
        else printf("%05d\n", list1[i+1].addr);
    }
    return 0;
}
