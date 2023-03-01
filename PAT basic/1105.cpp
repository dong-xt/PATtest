#include<iostream>
using namespace std;

struct Node
{
    int addr;
    int data;
    int next;
}list[100001];

int main()
{
    int head1, head2, n;
    cin >> head1 >> head2 >> n;
    for(int i = 0; i < n; i++)
    {
        int addr;
        cin >> addr;
        list[addr].addr = addr;
        cin >> list[addr].data >> list[addr].next;
    }
    int length1 = 0, length2 = 0;
    int ptr1 = head1, ptr2 = head2;
    while(ptr1 != -1 || ptr2 != -1)
    {
        if(ptr1 != -1)
        {
            length1++;
            ptr1 = list[ptr1].next;
        }
        if(ptr2 != -1)
        {
            length2++;
            ptr2 = list[ptr2].next;
        }
    }
    if(length1 < length2)   //1³¤2¶Ì
    {
        int temp = head1; head1 = head2; head2 = temp;
        temp = length1; length1 = length2; length2 = temp;
    }
    if(length2 > 1)
    {
        ptr2 = -1; int ptr2_next = head2;
        for(int i = 0; i < length2; i++)
        {
            int temp = list[ptr2_next].next;
            list[ptr2_next].next = ptr2;
            ptr2 = ptr2_next;
            ptr2_next = temp;
        }
        head2 = ptr2;
    }
    int cnt = 0; ptr1 = head1; ptr2 = head2;
    while(ptr1 != -1)
    {
        if(cnt == 1)
        {
            if(ptr2 != -1)
            {
                int temp = list[ptr1].next;
                list[ptr1].next = list[ptr2].addr;
                int temp2 = list[ptr2].next;
                list[ptr2].next = temp;
                ptr2 = temp2;
                ptr1 = temp;
            }
            cnt = 0;
        }
        else 
        {
            cnt++;
            ptr1 = list[ptr1].next;
        }
    }
    ptr1 = head1;
    while(ptr1 != -1)
    {
        printf("%05d %d ", list[ptr1].addr, list[ptr1].data);
        if(list[ptr1].next == -1) printf("-1\n");
        else printf("%05d\n", list[ptr1].next);
        ptr1 = list[ptr1].next;
    }
    return 0;
}
