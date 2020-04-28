#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999
typedef vector<vector<pair<int, int>>> graph;
graph g;

void dijkstra(int a, int b)
{

    vector<int> usados;
    vector<int> dists;
    int tamanho = g.size();
    usados.resize(tamanho, 0);
    dists.resize(tamanho, infinito);
    dists[a] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> fila;
    fila.emplace(make_pair(0, a));
    while (fila.size() > 0)
    {
        int atual = fila.top().second;

        fila.pop();
        for (int i = 0; i < g[atual].size(); i++)
        {
            int elemento = g[atual][i].second;

            if (dists[atual] + g[atual][i].first < dists[elemento])
            {
                // cout << atual << " " << elemento << " " << g[atual][i].first << endl;
                dists[elemento] = dists[atual] + g[atual][i].first;
            }
            if (!usados[elemento])
            {

                fila.emplace(make_pair(dists[elemento], elemento));
                usados[elemento] = 1;
            }
        }
    }
    // for (auto i : dists)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    cout << dists[b] << endl;
}
int main(int argc, const char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testes, cidades, conexoes, caminhos;

    cin >> testes;
    map<string, int> mapa;
    map<int, string> mapa_inv;

    for (int q = 0; q < testes; q++)
    {

        cin >> cidades;
        g.clear();
        g.resize(cidades);
        string temp;
        for (int i = 0; i < cidades; i++)
        {
            cin.ignore();

            getline(cin, temp);
            mapa[temp] = i;
            mapa_inv[i] = temp;
            cin >> conexoes;
            for (size_t c = 0; c < conexoes; c++)
            {
                int a, b;
                cin >> a >> b;
                g[a - 1].push_back(make_pair(b, i));
            }
        }
        cin >> caminhos;
        cin.ignore();
        for (int p = 0; p < caminhos; p++)
        {
            string a, b, c;
            getline(cin, a);
            // cout << a << endl;
            int control = 0;
            for (int l = 0; l < a.size(); l++)
            {
                // cout << a[l] << " ";
                if (a[l] == ' ')
                {
                    control = 1;
                }
                else
                {
                    if (control == 0)
                    {
                        b += a[l];
                    }
                    else
                    {
                        c += a[l];
                    }
                }
            }
            // cout << b << endl
            //  << c << endl;
            // cout << mapa[b] << " " << mapa[c] << endl;
            dijkstra(mapa[b], mapa[c]);
        }
        cout << endl;
    }
}