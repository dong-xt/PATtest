#include<iostream>
#include<string>
using namespace std;

int main()
{
    const char pd[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    string sa, sb, sc = "";
    cin >> sa >> sb;
    int la = sa.length(); int lb = sb.length();
    if(la > lb) sb = string(la - lb, '0') + sb; //如果a更长 还需要补0保证a遍历完成
    lb = sb.length();
    int l = la;
    int aidx = la - 1, bidx = lb - 1;
    for(int i = 1; i <= l; i++)
    {
        int rs;
        if(i % 2 == 1)
        {
            rs = (sa[aidx] - '0' + sb[bidx] - '0') % 13;
            sc = pd[rs] + sc;
            aidx--; bidx--;
        }
        else
        {
            rs = sb[bidx] - sa[aidx];
            if(rs < 0) rs += 10;
            sc = pd[rs] + sc;
            aidx--; bidx--;
        }
    }
    if(la < lb)
        sc = sb.substr(0, lb - la) + sc;
    cout << sc << endl;
    return 0;
}
