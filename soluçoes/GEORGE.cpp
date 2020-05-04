#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define infinito 9999999
typedef vector<vector<pair<int, int>>> graph;
vector<int> rota_george;
int n, m, a, b, k, g;
map<pair<int, int>, pair<int, int>> helper;
graph grafo;
int remaining(int expended, int atual_node, int togo_node)
{

    //take time expended untill now from the driver,where he is and where he want to go , and return how much time he has to wait
    expended += k;
    if (helper.count(make_pair(atual_node, togo_node)) > 0)
    {

        int mn = min(helper[make_pair(atual_node, togo_node)].first, helper[make_pair(atual_node, togo_node)].second);
        int mx = max(helper[make_pair(atual_node, togo_node)].second, helper[make_pair(atual_node, togo_node)].first);

        if (expended >= mx || expended < mn)
        {

            return 0;
        }
        else
        {

            return mx - expended;
        }
    }
    else
    {
        return 0;
    }
}
// simple djisktra ,but considering the waiting time.
void dijkstra(int inicio, int end)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    vector<int> usados;
    vector<int> distancias;
    usados.resize(grafo.size(), 0);
    distancias.resize(grafo.size(), infinito);
    distancias[inicio] = 0;
    fila.emplace(make_pair(0, inicio));

    while (fila.size() > 0)
    {
        int atual = fila.top().second;
        usados[atual] = 1;
        for (int i = 0; i < grafo[atual].size(); i++)
        {
            int elemento = grafo[atual][i].second;
            if (usados[elemento] == 0)
            {
                int peso = grafo[atual][i].first;
                //remaining returns the waiting in a intersection with a given time
                peso += remaining(distancias[atual], atual, elemento);

                if (distancias[elemento] > distancias[atual] + peso)
                {
                    distancias[elemento] = distancias[atual] + peso;
                    fila.emplace(make_pair(distancias[elemento], elemento));
                }
            }
        }
        fila.pop();
    }
    cout << distancias[end] << endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    grafo.resize(n);
    cin >> a >> b >> k >> g;
    rota_george.resize(g);
    for (int i = 0; i < g; i++)
    {
        cin >> rota_george[i];
        rota_george[i] -= 1;
    }
    int x, y, t;
    //creating graph
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> t;
        grafo[x - 1].push_back(make_pair(t, y - 1));
        grafo[y - 1].push_back(make_pair(t, x - 1));
    }
    // making helper map for remaining func

    int sum = 0;
    for (int i = 0; i < g - 1; i++)
    {

        int atual = rota_george[i];
        int elemento = rota_george[i + 1];

        for (int j = 0; j < grafo[atual].size(); j++)
        {

            if (grafo[atual][j].second == elemento)
            {

                helper[make_pair(elemento, atual)] = make_pair(sum, sum + grafo[atual][j].first);
                helper[make_pair(atual, elemento)] = make_pair(sum, sum + grafo[atual][j].first);
                // cout << helper[make_pair(elemento, atual)].first << " " << helper[make_pair(elemento, atual)].second << endl;
                // cout << atual << " " << elemento << endl;
                sum += grafo[atual][j].first;
                break;
            }
        }
    }

    dijkstra(a - 1, b - 1);
}
