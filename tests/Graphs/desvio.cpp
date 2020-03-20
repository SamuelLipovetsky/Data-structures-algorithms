#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, c, k, x, y, t;
    int adj[251][251] = {};
    int visitados[251] = {};
    int dists[251] = {};
    // while (1)
    // {
    cin >> n >> m >> c >> k;

    for (int i = 0; i < n; i++)
    {
        visitados[i] = 0;
        dists[i] = INT32_MAX;
        for (int j = 0; j < n; j++)
        {
            adj[i][k] = 0;
            adj[k][i] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> t;
        adj[x][y] = t;
        adj[y][x] = t;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    dists[k] = 0;
    q.push(k);
    int go;
    int min = INT32_MAX;

    for (int i = 0; i < n; i++)
    {
        cout << dists[i] << " ";
    }
    // }
}