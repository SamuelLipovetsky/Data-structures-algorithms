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

#define max 99999

typedef pair<int, int> node;
typedef vector<vector<node>> graph;
void dijkstra(graph g, int u, int v)
{

    // Variaveis;
    vector<int> peso;
    priority_queue<node> fila;
    int atual, elemento, custo;

    peso.resize(g.size(), max);

    peso[u] = 0;

    fila.push(make_pair(0, u));

    while (!fila.empty())
    {

        atual = fila.top().second;
        fila.pop();

        for (int cont = 0; cont < g[atual].size(); cont++)
        {
            custo = g[atual][cont].first;
            elemento = g[atual][cont].second;

            if (peso[elemento] > peso[atual] + custo)
            {
                peso[elemento] = peso[atual] + custo;
                fila.push(make_pair(peso[elemento], elemento));
            }
        }
    }

    if (peso[v] == max)
    {
        cout << "-1\n";
    }
    else
    {
        cout << peso[v] << endl;
    }
}

int main()
{

    int n, m;
    int a, b, custo;
    graph g;
    node vertice;
    pair<int, int> no;

    while (true)
    {
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        g.clear();
        g.resize(n);

        for (int cont = 0; cont < m; cont++)
        {
            cin >> a >> b >> custo;
            g[a - 1].push_back(make_pair(custo, b - 1));
        }

        cin >> a >> b;

        dijkstra(g, a - 1, b - 1);
    }

    return 0;
}