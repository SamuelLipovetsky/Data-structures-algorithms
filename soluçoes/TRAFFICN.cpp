#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
#define infinito 9999999
using namespace std;
typedef vector<vector<pair<int, int>>> graph;
int distancia_indo[10002];
int distancia_voltando[10002];
void dijkstra(int inicial, int distancias[10002], graph g)
{
    int n = g.size();

    for (int i = 0; i < n; i++)
    {
        distancias[i] = infinito;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    distancias[inicial] = 0;
    fila.emplace(make_pair(0, inicial));
    while (fila.size() > 0)
    {
        int atual = fila.top().second;

        for (int i = 0; i < g[atual].size(); i++)
        {

            int elemento = g[atual][i].second;
            int peso = g[atual][i].first;

            if (distancias[elemento] > distancias[atual] + peso)
            {
                distancias[elemento] = distancias[atual] + peso;
                fila.emplace(make_pair(distancias[elemento], elemento));
            }
        }
        fila.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p;
    cin >> p;
    for (int l = 0; l < p; l++)
    {

        int n, m, k, s, t;
        cin >> n >> m >> k >> s >> t;
        int x, y, c;
        vector<array<int, 3>> ways;
        graph indo;
        graph voltando;
        indo.resize(n);
        voltando.resize(n);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> c;
            indo[x - 1].push_back(make_pair(c, y - 1));
            voltando[y - 1].push_back(make_pair(c, x - 1));
        }
        dijkstra(s - 1, distancia_indo, indo);
        dijkstra(t - 1, distancia_voltando, voltando);
        int minimo = distancia_indo[t - 1];
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y >> c;
            minimo = min(minimo, min(distancia_indo[x - 1] + c + distancia_voltando[y - 1], distancia_indo[y - 1] + c + distancia_voltando[x - 1]));
        }
        if (minimo == infinito)
            cout << -1 << endl;
        else
            cout << minimo << endl;
    }
}
