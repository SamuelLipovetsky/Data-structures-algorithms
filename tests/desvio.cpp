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

    cout << dists[fim] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, c, k, x, y, t;
    grafo g;
    while (true)
    {

        cin >> n >> m >> c >> k;
        if (n == 0 && m == 0 && c == 0 && k == 0)
        {

            break;
        }
        g.clear();
        g.resize(n);
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y >> t;
            if (x < c - 1 || y < c - 1)
            {
                if (y == x + 1)
                {
                    g[x].push_back(make_pair(t, y));
                }
                else if (x == y + 1)
                {
                    g[y].push_back(make_pair(t, x));
                }
                else
                {
                    if (x > y + 1)
                    {
                        g[x].push_back(make_pair(t, y));
                    }
                    if (y > x + 1)
                    {
                        g[y].push_back(make_pair(t, x));
                    }
                }
            }
            else
            {
                g[x].push_back(make_pair(t, y));
                g[y].push_back(make_pair(t, x));
            }
        }

        dijkstra(g, k, c - 1);
    }
    return 0;
}