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
using namespace std;
#define max 999999
typedef pair<int, int> nodes;
typedef vector<vector<nodes>> graph;
void Dijkstra(graph g)
{
    vector<int> buracos;
    buracos.resize(g.size(), max);
    buracos[0] = 0;
    priority_queue<nodes, vector<nodes>, greater<nodes>> fila;
    fila.push(make_pair(0, 0));
    while (fila.size() > 0)
    {
        int atual = fila.top().second;
        fila.pop();
        for (int i = 0; i < g[atual].size(); i++)
        {
            int elemento = g[atual][i].second;
            int custo = g[atual][i].first;
            if (buracos[elemento] > buracos[atual] + custo)
            {
                buracos[elemento] = buracos[atual] + custo;
                fila.push(make_pair(buracos[elemento], elemento));
            }
        }
    }
    cout << buracos[g.size() - 1] << endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y, t;
    cin >> n >> m;
    graph g;
    g.resize(n + 2);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> t;
        g[x].push_back(make_pair(t, y));
        g[y].push_back(make_pair(t, x));
    }
    Dijkstra(g);
}