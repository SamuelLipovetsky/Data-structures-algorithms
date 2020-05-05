#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <math.h>
#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> pares;
long double dist(pair<int, int> a, pair<int, int> b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cout << fixed;
    cout << setprecision(3);
    int a, b;
    cin >> n;
    if (n == 0 || n == 1)
        cout << 0.000 << endl;
    else
    {
        pares.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            pares[i] = make_pair(a, b);
        }
        long double m = 99999999999999999;
        for (auto i : pares)
        {
            for (auto j : pares)
            {
                if (i != j)
                    m = min(m, dist(i, j));
            }
        }
        cout << m << endl;
    }
}
