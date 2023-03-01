#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool down(int a, int b)
{
    return a > b;
}

string addition(int a)
{
    if(a < 10)
        return "000";
    else if(a < 100)
        return "00";
    else if(a < 1000)
        return "0";
    else
        return "";
}

int main()
{
    int n;
    cin >> n;
    int arr[4];
    if(n % 1111 == 0 || n == 0000)
        cout << n << " - " << n << " = 0000" << endl;
    else
    {
        int a = 0;
        int b = 0;
        int error = 1;
        while(error != 6174)
        {
            arr[0] = n % 10;
            arr[1] = (n / 10) % 10;
            arr[2] = (n / 100) % 10;
            arr[3] = (n / 1000) % 10;
            sort(arr, arr + 4, down);
            a = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
            sort(arr, arr + 4);
            b = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];
            error = a - b; n = error;
            cout << a << " - " << addition(b) << b << " = " << addition(error) << error <<endl;
        }
    }
    return 0;
}
