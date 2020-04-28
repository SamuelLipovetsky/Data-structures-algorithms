#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <math.h>
using namespace std;
#define max 9999999
typedef pair<int, int> node;
typedef vector<vector<node>> graph;
void dijkstra(graph g, int o, int d, int t)
{
    vector<int> dists;
    dist.resize(g.size(), max);
    vector<int> usados;
    usados.resize(g.size(), 0);
    dists[o] = 0;
    priority_queue<node, vector<node>, greater<node>> fila;
    fila.push(make_pair(dists[o], o));
    while (fila.size() > 0)
    {
        int atual = fila.top().second;
        fila.pop();
        for (int i = 0; i < g[atual].size(); i++)
        {
            int elemento = g[atual][i].second;
            int peso = g[atual][i].first;
            if (usados[elemento] == 0 && dists[elemento] > dists[atual] + peso)
            {
                if (elemento <= t)
                {
                    dists[elemento] = dists[atual] + peso;
                    fila.push(make_pair(dists[elemento], elemento));
                }
            }
        }
    }
    cout << dists[d] << endl;
}
int bfs(pair<int, int> c, int no)
{
    queue<pair<int, int>> fila;

    distancias[c.first][c.second][no] = 0;
    fila.emplace(c);
    int usados[21][21] = {{0}};
    while (!fila.empty())
    {
        int x = fila.front().first;
        int y = fila.front().second;
        fila.pop();
        usados[x][y] = 1;
        for (int i = 0; i < 4; i++)
        {

            if (!usados[x + posx[i]][y + posy[i]] && safe(x + posx[i], y + posy[i]))
            {

                fila.push(make_pair(x + posx[i], y + posy[i]));

                if (distancias[x + posx[i]][y + posy[i]][no] > distancias[x][y][no] + 1)
                {
                    distancias[x + posx[i]][y + posy[i]][no] = distancias[x][y][no] + 1;
                }
            }
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    graph g;
    int n, m, u, v, w, c;
    g.clear();
    g.resize(n);
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g[u - 1].push_back(make_pair(w, v - 1));
        g[v - 1].push_back(make_pair(w, u - 1));
    }
    cin >> c;
    int o, d, t;
    for (int i = 0; i < c; i++)
    {

        cin >> o >> d >> t;
        dijkstra(g, o - 1, d - 1, t - 1);
    }
}