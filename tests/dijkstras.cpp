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
using namespace std;
#define max 999999
typedef pair<int, int> no;
typedef vector<vector<no>> grafo;
vector<int> dists;
priority_queue<no> fila;
void dijkstra(grafo g, int inicio, int fim)
{
    dists.clear();
    dists.resize(g.size(), max);
    dists[inicio] = 0;

    fila.push(make_pair(dists[inicio], inicio));
    while (fila.size() > 0)
    {
        int atual = fila.top().second;

        fila.pop();
        for (int i = 0; i < g[atual].size(); i++)
        {
            int e = g[atual][i].second;
            int c = g[atual][i].first;
            if (dists[e] > dists[atual] + c)
            {
                dists[e] = dists[atual] + c;
                fila.push(make_pair(dists[e], e));
            }
        }
    }
    if (dists[fim] != max)
        cout << dists[fim] << endl;
    else
    {
        cout << -1 << endl;
    }
}
int main()
{
    int n, m, x, y, t, inicio, fim;
    grafo g;
    while (true)
    {

        cin >> n >> m;
        if (n == 0 && m == 0)
        {
            break;
        }
        g.clear();
        g.resize(n);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> t;
            g[x - 1].push_back(make_pair(t, y - 1));
        }
        cin >> inicio >> fim;
        dijkstra(g, inicio - 1, fim - 1);
    }
    return 0;
}