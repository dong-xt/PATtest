#include<iostream>
#include<algorithm>
using namespace std;

bool isequal(int n, int a[], int b[])
{
    for(int i = 0; i < n; i++)
        if(a[i] != b[i])
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    int a[n], a1[n], a2[n], a_gold[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a1[i];
        a2[i] = a1[i];
        a[i] = a1[i];
    }
    for(int i = 0; i < n; i++)
        cin >> a_gold[i];
    sort(a, a + n);
    int i1 = 2;     //要从2开始，第一轮插入排序迭代不能从一个元素开始
    /*
    测试点2如下:
    输入：
    3
    1 3 2
    1 3 2
    正确输出：
    1 2 3
    如果从i1从1开始 那么第一轮迭代132输出结果为132
    */
    int i2 = 0, dis = 2;
    while(1)
    {
        //insertion sort
        if(!isequal(n, a1, a))
        {
            sort(a1, a1 + i1);
            if(isequal(n, a1, a_gold))
            {
                sort(a1, a1 + i1 + 1);
                cout << "Insertion Sort" << endl;
                for(int i = 0; i < n - 1; i++)  cout << a1[i] << " ";
                cout << a1[n-1] << endl;
                break;
            }
            i1++;
        }
        //merge sort
        if(!isequal(n, a2, a))
        {
            while(i2 < n && i2 + dis <= n)
            {
                sort(a2 + i2, a2 + i2 + dis);
                i2 += dis;
            }
            sort(a2 + i2, a2 + n);
            dis *= 2; i2 = 0;
            if(isequal(n, a2, a_gold))
            {
                while(i2 < n && i2 + dis <= n)
                {
                    sort(a2 + i2, a2 + i2 + dis);
                    i2 += dis;
                }
                sort(a2 + i2, a2 + n);
                cout << "Merge Sort" << endl;
                for(int i = 0; i < n - 1; i++)  cout << a2[i] << " ";
                    cout << a2[n-1] << endl;
                break;
            }            
        }
    }
    
    return 0;
}
