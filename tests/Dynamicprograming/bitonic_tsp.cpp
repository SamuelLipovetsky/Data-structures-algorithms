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
double euclidian(pair<int, int> a, pair<int, int> b)
{

    return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}
int main()
{
    cin >> n;
    pair<int, int> pares[n];
    // double dp[n][n];
    for (int i = 0; i < n; i++)
    {
        cin >> pares[i].first;
        cin >> pares[i].second;
    }

    double dp[n] = {};
    dp[0] = 0;
    double c[n] = {};
    int f[n] = {};
    f[0] = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     c[i] = INT16_MAX;
    // }

    for (int i = 1; i < n - 1; i++)
    {
        dp[i] = euclidian(pares[i], pares[i - 1]);
    }

    for (int e = 0; e < n - 1; e++)
    {
        for (int i = 0; i < n; i++)
        {
            if (e < i)
            {
                if (i == 2)
                {
                    c[i] = euclidian(pares[i - 1], pares[i]);
                    f[i] = f[i - 1];
                }
                else if (i - e == 1)
                {
                    double temp = c[i - 1] + euclidian(pares[i - 1], pares[i]);

                    if (temp < c[i] || c[i] == 0)
                    {
                        c[i] = temp;
                    }
                    f[i] = f[i - 1];
                }
                else if (e < i - 1)
                {
                    f[i] = i - 1;
                    double temp = c[e] + euclidian(pares[e], pares[i]) + euclidian(pares[f[e]], pares[e + 1]) + dp[i - 1] - dp[max(e - 1, 0)];

                    if (temp < c[i] || c[i] == 0)
                    {
                        c[i] = temp;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << c[i] << " ";
    }
    // cout << c[n - 1] + euclidian(pares[f[n - 1]], pares[n - 1]);
}
