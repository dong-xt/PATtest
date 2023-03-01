#include<iostream>
#include<algorithm>
using namespace std;

struct Node
{
    int addr;
    int data;
    int next;
}list[100001];
int head, n, k;

int main()
{
    cin >> head >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int addr;
        cin >> addr;
        list[addr].addr = addr;
        cin >> list[addr].data >> list[addr].next;
    }
    int ptr = head;
    Node list1[n], list2[n], list3[n];
    int length1 = 0, length2 = 0, length3 = 0;
    while(ptr != -1)
    {
        if(list[ptr].data < 0)
        {
            list1[length1] = list[ptr];
            length1++;
        }
        else if(list[ptr].data >= 0 && list[ptr].data <= k)
        {
            list2[length2] = list[ptr];
            length2++;            
        }
        else
        {
            list3[length3] = list[ptr];
            length3++;                
        }
        ptr = list[ptr].next;
    }
    for(int i = 0; i < length1; i++)
    {
        printf("%05d %d ", list1[i].addr, list1[i].data);
        if(i != length1 - 1) printf("%05d\n", list1[i + 1].addr);
        else if(length2 == 0 && length3 == 0) printf("-1\n");
    }
    for(int i = 0; i < length2; i++)
    {
        if(i == 0 && length1 != 0) printf("%05d\n", list2[0].addr);
        printf("%05d %d ", list2[i].addr, list2[i].data);
        if(i != length2 - 1) printf("%05d\n", list2[i + 1].addr);
        else if(length3 == 0) printf("-1\n");
    }
    for(int i = 0; i < length3; i++)
    {
        if(i == 0 && (length1 != 0 || length2 != 0)) printf("%05d\n", list3[0].addr);
        printf("%05d %d ", list3[i].addr, list3[i].data);
        if(i != length3 - 1) printf("%05d\n", list3[i + 1].addr);
        else printf("-1\n");
    }
    return 0;
}
