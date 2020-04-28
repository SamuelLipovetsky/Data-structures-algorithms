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
    int n, m, i, j, t, inicio, fim;

    queue<int> q;
    while (1)
    {

        cin >> n >> m;
        int adj[200][200] = {};

        bool usados[200] = {};
        int dist[200] = {};
        if (n == 0 || m == 0)
            break;

        for (int k = 0; k < m; k++)
        {
            cin >> i >> j >> t;
            adj[i - 1][j - 1] = t;
        }
        cin >> inicio >> fim;
        fim--;
        inicio--;
        if (inicio == fim)
        {
            cout << 0 << endl;
        }
        else
        {
            // bfs mantendo as distantcias;

            q.emplace(inicio);

            while (q.size() > 0)
            {
                usados[q.front()] = true;
                for (int i = 0; i < n; i++)
                {
                    if (adj[q.front()][i] && usados[i] == false)
                    {
                        q.emplace(i);
                        if (i != inicio)
                        {
                            if (dist[i] == 0)
                                dist[i] = dist[q.front()] + adj[q.front()][i];
                            else
                            {
                                dist[i] = min(dist[q.front()] + adj[q.front()][i], dist[i]);
                            }
                        }
                    }
                }
                q.pop();
            }

            if (dist[fim])
                cout << dist[fim] << endl;
            else
                cout << -1 << endl;
        }
    }
}