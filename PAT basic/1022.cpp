#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    unsigned int A, B, D;
    cin >> A >> B >> D;
    //10����תn���� ��nȡ�෨
    unsigned int c = A + B;
    string dtype = "";
    if(c == 0) dtype = "0";
    else
    {
        while(c != 0)
        {
            dtype = (char)((c % D) + '0') + dtype;
            c = c / D;
        }        
    }
    cout << dtype << endl;
    return 0;
}
