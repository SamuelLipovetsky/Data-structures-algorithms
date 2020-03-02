#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <string>
#include <math.h>
#include <set>
using namespace std;
#define great 100000000000

int n;
double euclidian(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}
int main()
{
    cin >> n;
    pair<int, int> pares[n];
    double dists[n][n];
    for (int i = 0; i < n; i++)
    {
        cin >> pares[i].first;
        cin >> pares[i].second;
    }
    double lower_bound = 0;
    double min_temp = great;
    double to_sum = 0;
    for (int i = 0; i < n; i++)
    {
        min_temp = great;
        for (int j = 0; j < n; j++)
        {
            if (j != i)
            {
                dists[i][j] = euclidian(pares[i].first, pares[i].second, pares[j].first, pares[j].second);
            }
            else
            {
                dists[i][j] = great;
            }
            if (dists[i][j] < min_temp)
            {
                min_temp = dists[i][j];
            }
        }
        if (i == 0)
        {
            to_sum += min_temp;
        }
        lower_bound += min_temp;
    }
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << dists[i][j] << " ";
        }
        cout << endl;
    }
}
