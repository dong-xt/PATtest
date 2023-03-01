#include <iostream>
#include <string>
using namespace std;

string symbol[10] = {"ling","yi","er","san","si","wu","liu",
                    "qi","ba","jiu"};

int main()
{
    string n;
    cin >> n;
    int l = n.length();
    int sum = 0;
    for(int i = 0; i < l; i++)
    {
        sum += (n[i] - '0');
    }
    int last = sum % 10;
    int middle = (sum / 10) % 10;
    int start = (sum / 100) % 10;
    if(sum >= 100)
    {
        cout << symbol[start] + " " + symbol[middle] + " " + symbol[last] << endl;
    }
    else if(sum >= 10)
    {
        cout << symbol[middle] + " " + symbol[last] << endl;
    }
    else
    {
        cout << symbol[last] << endl;
    }
    
    return 0;
}
