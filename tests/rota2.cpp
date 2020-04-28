

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
#define infinito 9999999
map<string, int> mapa_inv;
map<int, string> mapa;
string a, b;
string temp;
vector<vector<char>> all;
typedef vector<vector<pair<int, int>>> graph;
map<int, string> mapa_caminho;
graph g;
vector<int> can_go;

int bfs(int inicio, int capital)
{
    vector<int> usados_local;
    queue<int> q;
    q.emplace(inicio);

    usados_local.resize(g.size(), 0);

    while (q.size() > 0)
    {

        int atual = q.front();

        for (int i = 0; i < g[atual].size(); i++)
        {

            int elemento = g[atual][i].first;

            if (elemento == capital || can_go[elemento])
            {
                can_go[inicio] = 1;
                return true;
            }
            if (usados_local[elemento] == 0)
            {
                usados_local[elemento] = 1;

                q.emplace(elemento);
            }
        }
        q.pop();
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;

    while (true)
    {
        cin >> n >> m;

        int crit_table[n][n] = {{0}};
        g.clear();
        g.resize(n);
        cin.ignore();
        if (n == 0 || m == 0)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            getline(cin, temp);
            mapa[i] = temp;
            mapa_inv[temp] = i;
        }

        for (int i = 0; i < m; i++)
        {
            getline(cin, temp);
            int control = 0;
            mapa_caminho[i] = temp;
            a.clear();
            b.clear();
            for (auto i : temp)
            {

                if (i == ' ')
                    control = 1;
                else if (control == 0)
                    a += i;
                else
                    b += i;
            }
            g[mapa_inv[a]].push_back(make_pair(mapa_inv[b], i));
        }

        vector<int> order;
        can_go.resize(n);
        for (int i = 0; i < g.size(); i++)
        {

            for (int j = 0; j < g[i].size(); j++)
            {
                fill(can_go.begin(), can_go.end(), 0);

                int t = g[i][j].first;
                int t2 = g[i][j].second;
                g[i].erase(g[i].begin() + j);
                for (int k = 1; k < g.size(); k++)
                {

                    if (!bfs(k, 0) && crit_table[i][t] == 0)
                    {
                        crit_table[i][t] = 1;
                        // crit.push_back(make_pair(i, t));
                        order.push_back(t2);
                    }
                }
                g[i].push_back(make_pair(t, t2));
            }
        }
        // cout << endl;

        sort(order.begin(), order.end());
        if (order.size() == 0)
        {
            cout << "Nenhuma" << endl
                 << endl;
        }
        else
        {
            for (auto i : order)
            {
                // cout << i.first << " " << i.second << endl;
                cout << mapa_caminho[i] << endl;
            }
            cout << endl;
        }
    }
}