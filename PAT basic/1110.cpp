#include<iostream>
#include<string>
using namespace std;

struct Node
{
    int address;
    int data;
    int next_address;
}list[100001];

int main()
{
    int head_address, n, k;
    cin >> head_address >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int idx;
        cin >> idx;
        list[idx].address = idx;
        cin >> list[idx].data >> list[idx].next_address;
    }
    int ptr_address = head_address;
    int lastfirst = -1, first = -1;
    int cnt = 0;
    while(ptr_address != -1)
    {	
        if(cnt == 0)
        {
            lastfirst = first;
            first = ptr_address;
        }
        int temp_nextaddr;
        if(cnt == k - 1 || list[ptr_address].next_address == -1)
        {
			temp_nextaddr = list[ptr_address].next_address;     			
            list[ptr_address].next_address = lastfirst;
            ptr_address = temp_nextaddr;
            cnt = 0;
            if(ptr_address == -1)
            	head_address = first;
        }
        else
		{
			cnt++;
			ptr_address = list[ptr_address].next_address;
		}
    }
    ptr_address = head_address;
    while(ptr_address != -1)
    {
        printf("%05d %d ", list[ptr_address].address, list[ptr_address].data);
        if(list[ptr_address].next_address != -1) printf("%05d\n", list[ptr_address].next_address);
        else printf("-1\n");
        ptr_address = list[ptr_address].next_address;
    }
    return 0;
}
