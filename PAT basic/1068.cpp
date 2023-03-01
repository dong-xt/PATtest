#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;

struct POINT{
    int x;
    int y;
    int color;
};

map<int, int> mymap;
map<int, int>::iterator it;

//边界需要检测  重复点不选择
POINT p[1000000];
int main()
{
    int m, n, tol;
    cin >> m >> n >> tol;
    int image[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        {
            cin >> image[i][j];
            it = mymap.find(image[i][j]);
            if(it == mymap.end()) mymap.emplace(image[i][j], 1);
            else it -> second++;
        }
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            it = mymap.find(image[i][j]);
            if(it->second == 1)
            {
                if(abs(image[i][j] - image[i - 1][j - 1]) <= tol && i - 1 >= 0 && j - 1 >= 0)
                    continue;
                if(abs(image[i][j] - image[i - 1][j]) <= tol && i - 1 >= 0)
                    continue;
                if(abs(image[i][j] - image[i - 1][j + 1]) <= tol && i - 1 >= 0 && j + 1 < m)
                    continue;
                if(abs(image[i][j] - image[i][j - 1]) <= tol && j - 1 >= 0)
                    continue;
                if(abs(image[i][j] - image[i][j + 1]) <= tol && j + 1 < m)
                    continue;
                if(abs(image[i][j] - image[i + 1][j - 1]) <= tol && i + 1 < n && j - 1 >=0)
                    continue;
                if(abs(image[i][j] - image[i + 1][j]) <= tol && i + 1 < n)
                    continue;
                if(abs(image[i][j] - image[i + 1][j + 1]) <= tol && i + 1 < n && j + 1 < m)
                    continue;
                mymap.emplace(image[i][j], 1);
                p[cnt].x = j + 1; p[cnt].y = i + 1; p[cnt].color = image[i][j];
                cnt++;                
            }
        }
    }
    
    if(cnt == 0)
        cout << "Not Exist" << endl;
    else if(cnt == 1)
        cout << "(" << p[0].x << ", " << p[0].y << "): " << p[0].color << endl;
    else
        cout << "Not Unique" << endl;        
    
    return 0;
}
