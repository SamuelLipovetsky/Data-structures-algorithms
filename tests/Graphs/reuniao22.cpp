#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999
map<vector<char>, int> mapa_inv;
map<int, vector<char>> mapa;
vector<char> a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y, t;
    cin >> n >> m;

    int dists[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dists[i][j] = 0;
            }
            else
            {
                dists[i][j] = infinito;
                dists[j][i] = infinito;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> t;
        if (dists[x][y] > t && dists[y][x] > t)
        {
            dists[x][y] = t;
            dists[y][x] = t;
        }
    }

    cout << maior_all << endl;
}